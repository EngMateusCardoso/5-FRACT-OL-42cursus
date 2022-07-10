/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:08:31 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/10 02:18:41 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia_nbr(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	index++;
	if (!(nbr[index] == '.'))
		return (0);
	index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	while (ft_isdigit(nbr[index]))
		index++;
	if (nbr[index])
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp("mandelbrot", argv[1], ft_strlen("mandelbrot")))
			return (1);
		return (0);
	}
	else if (argc == 4)
	{
		if (!ft_strncmp("julia", argv[1], ft_strlen("julia")) \
		&& check_julia_nbr(argv[2]) && check_julia_nbr(argv[3]))
			return (1);
		return (0);
	}
	return (0);
}

void	start_image(t_win *win)
{
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, WIN_SIDE, WIN_SIDE);
	win->img.addr = mlx_get_data_addr(win->img.img_ptr, &win->img.bpp, \
	&win->img.line_len, &win->img.endian);
	mandelbrot(win->img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
}

int	start_window(void)
{
	t_win	win;

	win.img.xmin = -2;
	win.img.xmax = 2;
	win.img.ymin = -2;
	win.img.ymax = 2;
	win.img.color = BLUE;
	win.img.range = 5;
	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		return (MLX_ERROR);
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_SIDE, WIN_SIDE, "Fract-ol");
	if (win.win_ptr == NULL)
	{
		free(win.mlx_ptr);
		return (MLX_ERROR);
	}
	start_image(&win);
	mlx_mouse_hook(win.win_ptr, zoom, &win);
	mlx_hook(win.win_ptr, 2, 1L<<0, &handle_input, &win);
	mlx_hook(win.win_ptr, 17, 1L<<0, &close_window, &win);
	mlx_expose_hook(win.win_ptr, (void *)start_image, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		start_window();
	}
	else
	{
		ft_putstr_fd("\nWrong arguments bad request!\n", 1);
		ft_putstr_fd("----------------------------\n", 1);
		ft_putstr_fd("Try something like this:\n\n", 1);
		ft_putstr_fd("./fractol mandelbrot\n", 1);
		ft_putstr_fd("./fractol julia x.xxx x.xxx\n", 1);
	}
	return (0);
}
