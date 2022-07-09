
#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
//erase
#include <stdio.h>

# define WIN_SIDE 500
# define MLX_ERROR 1
# define MAX_ITER 100
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BLACK 0x00000000

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	pass;
	int		color;
	int		range;
}				t_img;

typedef struct	s_win {
	void	*mlx_ptr;
	char	*win_ptr;
	char	*name;
	double	*julia_x;
	double	*julia_y;
	t_img	img;
}				t_win;

void	start_image(t_win *win);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 	close_window(t_win *win);

int		handle_input(int keysys, t_win *win);
int		zoom(int keysys, int x, int y, t_win *win);

void    mandelbrot(t_img	img);

#endif
