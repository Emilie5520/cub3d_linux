

NAME = Cub3D

CC = gcc 

SRC_DIR = sources

SRC =  sources/main.c \
	sources/ft_parsing.c \
	sources/ft_parsing_2.c \
	sources/ft_read_map.c \
	sources/ft_window.c \
	sources/ft_orientation.c \
	sources/ft_deplacements.c \
	sources/ft_textures.c \
	sources/ft_bmp.c \
	sources/ft_sprite.c \
	sources/ft_utils.c \
	sources/ft_check_error.c \
	sources/ft_utils_2.c \
	sources/ft_utils_3.c \
	sources/ft_utils_4.c \
	sources/ft_sprite_2.c \

OBJ = $(SRC:%.c=%.o)

IFLAGS = ./includes/

CFLAGS = -Wall -Wextra -Werror -lm -lbsd -lX11 -lXext -g

DIRMLX = ./mlx/

DIRLIB = ./libft/

NAMELIB = libft.a

NAMEMLX = libmlx.a

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -I$(IFLAGS) -I$(DIRMLX) -I$(DIRLIB) $< -o $(<:.c=.o) 

$(NAME): $(OBJ)
	cd ./libft/ && make
	cd $(DIRMLX)/ && make
	gcc -o $(NAME) -I$(IFLAGS) -I$(DIRMLX) $(OBJ) $(DIRMLX)$(NAMEMLX) $(DIRLIB)$(NAMELIB) $(DIRMLX)/libmlx_Linux.a $(CFLAGS)

clean:
	make clean -C libft
	make clean -C $(DIRMLX)
	rm -f $(SRC_DIR)/*.o

fclean: clean
	make fclean -C libft
	make clean -C $(DIRMLX)
	rm -f $(NAME)

show:
	@echo "CFLAGS :\n  $(CFLAGS)"
	@echo "IFLAGS :\n  $(IFLAGS)"

re: fclean all



.PHONY: all clean fclean re
