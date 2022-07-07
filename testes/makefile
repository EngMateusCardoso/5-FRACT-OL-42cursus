
NAME	= fratol.a

#OBJ		= main.o

SRC		= main_mand2.c

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

$(NAME):
	$(CC) $(SRC) ./minilibx-linux/libmlx.a -lXext -lX11 -lmlx

#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#%.o: %.c
#	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

#libmlx.a