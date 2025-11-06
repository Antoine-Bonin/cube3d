.PHONY: all re clean fclean libft_make mlx_make

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
		errors/print_errors \
		free_malloc/free_parsing_data \
		parsing/00-start_of_parsing \
		parsing/01-check_cub_filename \
		parsing/02-parse_cub_file \
		parsing/03-parse_cub_file_utils \
		parsing/04-parse_texture_cub \
		parsing/05-parse_color_cub \
		parsing/06-parse_map_cub \
		parsing/07-check_textures_path \
		parsing/08-check_floor_ceiling_color \
		parsing/09-check_char_map_validity \
		parsing/10-check_map_validity 

HEIGHT = 900
WIDTH = 1920

OBJ_DIR = build/
SRC_DIR = sources/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(FILES)))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -DHEIGHT=$(HEIGHT) -DLENGTH=$(WIDTH) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(FLAGSMLX) $(FLAGLIBFT)
-include $(DEPS)

libft_make:
	$(MAKE) -C $(LIBFT_PATH)

mlx_make:
	$(MAKE) -C $(MLX_PATH)

$(LIBFT): libft_make

$(MLX): mlx_make

clean:
	rm -rf $(OBJ_DIR)
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