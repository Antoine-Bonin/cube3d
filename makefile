.PHONY :all re clean fclean

FLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT_PATH) -I$(MLX_PATH) -Iincludes -MD
FLAGSMLX =  -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm
FLAGLIBFT = -L$(LIBFT_PATH) -lft

CC = cc
NAME = cub3d
LIBFT_PATH = libft
MLX_PATH = minilibx-linux

MLX = $(MLX_PATH)/libmlx_Linux.a
LIBFT = $(LIBFT_PATH)/libft.a
FILES = main \

H = 900
L = 1920

OBJ_DIR = build/
SRC_DIR = sources/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(FILES)))

all: $(NAME)

$(OBJ_DIR): $(OBJS)
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(FLAGS) -DHEIGHT=$(H) -DLENGTH=$(L) -c $< -o $@

$(NAME): $(OBJ_DIR) $(MLX) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(FLAGSMLX) $(FLAGLIBFT)
-include $(DEPS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f $(MLX_PATH)/libmlx.a

resize: 
	$(MAKE) H=$(H) L=$(L) clean $(NAME)

re: fclean all