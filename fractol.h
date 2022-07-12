/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:09:10 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 04:43:44 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <math.h>

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
	int		type;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	pass;
	int		color;
	int		range;
	double	julia_x;
	double	julia_y;
	int		grau;
}				t_img;

typedef struct	s_win {
	void	*mlx_ptr;
	char	*win_ptr;
	t_img	img;
}				t_win;

// fractol.c
void	start_image(t_win *win);
//fractol_utils.c
double	convert_params(char *nbr);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int 	close_window(t_win *win);
// check_args.c
int		check_args(int argc, char **argv);
void	args_erro(void);
//Mandelbrot
int		mandelbrot(double x, double y, t_img *img);
//Julia
int		julia(double x,double y, t_img *img);
//Colors
void	set_color_mandelbrot(double x, double y, int i, t_img *img);
//hooks
int		handle_input(int keysys, t_win *win);
int		zoom(int keysys, int x, int y, t_win *win);

#endif
