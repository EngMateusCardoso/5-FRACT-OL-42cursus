
#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
//erase
#include <stdio.h>

# define WIN_SIDE 800
# define MLX_ERROR 1

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_win {
	void	*mlx_ptr;
	char	*win_ptr;
}				t_win;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 	close_window(t_win *win);

int		handle_input(int keysys, t_win *win);
int		zoom(int keysys, int x, int y);

void    mandelbrot(t_img	img);

#endif
