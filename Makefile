NAME = so_long
CC = cc
CFLAGS = -Werror -Wall -Wextra  -g -I. -I.. -Iminilibx-linux
SRC_FOLDER = src
SRCS = $(addprefix $(SRC_FOLDER)/, main.c parsing.c map_validation.c map_validation2.c images.c game.c)
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): libft.a $(OBJS)

	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) libft.a $(MLX_FLAGS) -o $(NAME)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'

libft.a:
	@make -s -C Libft
	@cp ./Libft/libft.a .

mlx:
	@git clone https://github.com/42Paris/minilibx-linux.git

clean:
	@find . -name '*.o' -delete
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo  'Biblioteca limpa!'
re: fclean all