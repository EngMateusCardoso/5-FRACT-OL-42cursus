/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:08:31 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 06:40:41 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_screen(t_img *img)
{
	double	x;
	double	y;
	int		i;

	img->pass = (img->xmax - img->xmin) / WIN_SIDE;
	x = img->xmin;
	while (x <= img->xmax)
	{
		y = img->ymin;
		while (y <= img->ymax)
		{
			if (img->type == 2 || img->type == 3)
				i = mandelbrot(x, y, img);
			else if (img->type == 4 || img->type == 5)
				i = julia(x, y, img);
			set_color_mandelbrot(x, y, i, img);
			y += img->pass;
		}
		x += img->pass;
	}
}

void	start_image(t_win *win)
{
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, WIN_SIDE, WIN_SIDE);
	win->img.addr = mlx_get_data_addr(win->img.img_ptr, &win->img.bpp, \
	&win->img.line_len, &win->img.endian);
	print_screen(&(win->img));
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
}

int	start_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return (MLX_ERROR);
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_SIDE, WIN_SIDE, "Fract-ol");
	if (win->win_ptr == NULL)
	{
		free(win->mlx_ptr);
		return (MLX_ERROR);
	}
	start_image(win);
	mlx_mouse_hook(win->win_ptr, zoom, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, &handle_input, win);
	mlx_hook(win->win_ptr, 17, 1L << 0, &close_window, win);
	mlx_expose_hook(win->win_ptr, (void *)start_image, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}

void	init_win(t_win *win, int argc, char **argv)
{
	win->img.type = argc;
	win->img.xmin = -2.0;
	win->img.xmax = 2.0;
	win->img.ymin = -2.0;
	win->img.ymax = 2.0;
	win->img.color = BLUE;
	win->img.range = 5;
	if (argc == 4)
	{
		win->img.julia_x = convert_params(argv[2]);
		win->img.julia_y = convert_params(argv[3]);
	}
	else if (argc == 5)
	{
		win->img.julia_x = convert_params(argv[3]);
		win->img.julia_y = convert_params(argv[4]);
	}
	if (argc == 3 || argc == 5)
	{
		win->img.grau = argv[2][0];
	}
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (check_args(argc, argv))
	{
		init_win(&win, argc, argv);
		start_window(&win);
	}
	else
		args_erro();
	return (0);
}
