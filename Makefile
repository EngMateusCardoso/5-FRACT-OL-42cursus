# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 02:09:58 by matcardo          #+#    #+#              #
#    Updated: 2022/07/10 02:10:00 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fractol

all: $(NAME)

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(MLX):
		make -C ./minilibx-linux
$(LIBFT):
		make -C ./libft

$(NAME): $(OBJS) $(MLX) $(LIBFT)
		$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

leaks: 
	$(LEAKS) $(LF)

clean:
		make -C ./libft clean
		$(RM) $(OBJS)

fclean:	clean
		make -C ./minilibx-linux clean
		make -C ./libft fclean
		$(RM) $(NAME)
