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

void	start_image(t_win *win)
{
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, WIN_SIDE, WIN_SIDE);
	win->img.addr = mlx_get_data_addr(win->img.img_ptr, &win->img.bpp, \
	&win->img.line_len, &win->img.endian);
	fractal(win->img);
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
	mlx_hook(win->win_ptr, 2, 1L<<0, &handle_input, win);
	mlx_hook(win->win_ptr, 17, 1L<<0, &close_window, win);
	mlx_expose_hook(win->win_ptr, (void *)start_image, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}

void	init_win(t_win *win, int argc, char **argv)
{
	win->img.name = argv[1][0];
	win->img.xmin = -2;
	win->img.xmax = 2;
	win->img.ymin = -2;
	win->img.ymax = 2;
	win->img.color = BLUE;
	win->img.range = 5;
	if (argc == 4)
	{
		win->img.julia_x = convert_params(argv[2]);
		win->img.julia_y = convert_params(argv[3]); 
	}
}

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

double	convert_params(char *nbr)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*nbr == '+' || *nbr == '-')
	{
		sign = -1;
		nbr++;
	}
	result = *nbr - 48;
	nbr += 2;
	result += (double)(ft_atoi(nbr))/(double)(ft_pow(10, ft_strlen(nbr)));
	return(result * sign);
}

int		main(int argc, char **argv)
{
	t_win	win;

	if (check_args(argc, argv))
	{
		init_win(&win, argc, argv);
		start_window(&win);
	}
	else //--------------------------------------------------------------------
	{
		ft_putstr_fd("\nWrong arguments bad request!\n", 1);
		ft_putstr_fd("----------------------------\n", 1);
		ft_putstr_fd("Try something like this:\n\n", 1);
		ft_putstr_fd("./fractol mandelbrot\n", 1);
		ft_putstr_fd("./fractol julia x.xxx x.xxx\n", 1);
		ft_putstr_fd("Julia ex.: (0.4, 0.6) (-0.4, -0.6) (0.0, 1.0)\n", 1);
		ft_putstr_fd("\t(0.285, 0.0) (0.285, 0.01) (-0.74, 0.12)\n", 1);
		ft_putstr_fd("\t(-1.312 0.0) (0.37, -0.28) (0.45, 0.1428)\n", 1);
		ft_putstr_fd("\t(-0.70176 -0.3842) (-0.835, -0.2321)\n", 1);// cabe 5
	}
	return (0);
}
