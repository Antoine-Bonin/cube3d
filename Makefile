.PHONY: all re clean fclean libft_rules bonus

FLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT_PATH)/includes -I$(MLX_PATH) -Iincludes -MD
FLAGSMLX =  -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm
FLAGLIBFT = -L$(LIBFT_PATH) -lft

CC = cc
NAME = cub3d
NAME_BONUS = cub3d_bonus
LIBFT_PATH = libft
MLX_PATH = minilibx-linux

MLX = $(MLX_PATH)/libmlx_Linux.a
LIBFT = $(LIBFT_PATH)/libft.a

FILES = main \
		init_main \
		errors/print_errors \
		cleanup/free_parsing \
		cleanup/free_game \
		cleanup/free_exit \
		parsing/00-parsing \
		parsing/01-check_cub_filename \
		parsing/02-parse_cub_file \
		parsing/03-parse_cub_file_utils \
		parsing/04-parse_texture_cub \
		parsing/05-parse_color_cub \
		parsing/06-parse_map_cub \
		parsing/07-check_floor_ceiling_color \
		parsing/08-check_char_map_validity \
		parsing/09-check_map_validity \
		parsing/010-flood_fill \
		parsing/011-parse_game_data \
		parsing/012-parse_game_tile \
		parsing/013-tile_structure \
		window/init_window_and_textures \
		window/handle_keypress_and_release \
		window/move_player \
		window/move_mouse \
		window/count_fps \
		window/sprint \
		window/move_vision \
		window/set_and_check_keystate \
		minimap/choose_wich_minimap_to_use \
		minimap/draw_minimap \
		minimap/init_minimap \
		minimap/draw_minimap_big_map \
		minimap/generate_argb_minimap \
		draw/draw \
		draw/calc_for_dda \
		draw/calc_for_draw \
		draw/dda 

WIDTH = 1920
HEIGHT = 1080
OBJ_DIR = build/
SRC_DIR = sources/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(FILES)))

all: libft_rules $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -DHEIGHT=$(HEIGHT) -DLENGTH=$(WIDTH) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) -g3 -o $(NAME) $(OBJS) $(FLAGSMLX) $(FLAGLIBFT)
-include $(DEPS)

$(NAME_BONUS): $(OBJS) $(MLX)
	$(CC) $(FLAGS) -g3 -o $(NAME_BONUS) $(OBJS) $(FLAGSMLX) $(FLAGLIBFT)

	

$(MLX): 
	$(MAKE) -C $(MLX_PATH)

libft_rules: 
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f $(MLX_PATH)/libmlx.a
bonus : libft_rules $(NAME_BONUS)

re: fclean all