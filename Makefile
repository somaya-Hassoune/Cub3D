NAME = cub3D
CC = cc
CFLAGS =   -Wall -Wextra -Werror
FCLAGS = libmlx.a -Lminilibx-linux -lXext -lX11 -lm -lbsd
SRC =\
	main.c \
	mini_map/draw_map.c \
	cub_utils/cub_utils.c \
	cub_utils/cub_utils_0.c \
	mini_map/player.c \
	raycasting/DDA_0.c \
	raycasting/DDA_1.c \
	key_controll/key_hook_1.c \
	key_controll/key_hook_0.c \
	key_controll/key_hook_2.c \
	parsing/parsing.c parsing/ft_split.c \
	manage_textures/texture.c manage_textures/textures_utils.c \
	parsing/u.c  parsing/u1.c parsing/u2.c \
	parsing/get_next_line/get_next_line.c  \
	parsing/get_next_line/get_next_line_utils.c \
	parsing/final.c parsing/ft_atoi.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FCLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
