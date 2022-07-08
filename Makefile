
NAME		= fractol

SRCS		= fractol.c		\
			fractol_utils.c	\
			mandelbrot.c	\
			hook.c
OBJS		= ${SRCS:.c=.o}

RM			= rm -f
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
MLX			= ./minilibx-linux/libmlx.a
MLX_FLAGS	= -lXext -lX11 -lmlx
LIBFT		= ./libft/libft.a

all: $(NAME)

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(MLX):
		make -C ./minilibx-linux
$(LIBFT):
		make -C ./libft

$(NAME): $(OBJS) $(MLX) $(LIBFT)
		$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

clean:
		make -C ./libft clean
		$(RM) $(OBJS)

fclean:	clean
		make -C ./minilibx-linux clean
		make -C ./libft fclean
		$(RM) $(NAME)
