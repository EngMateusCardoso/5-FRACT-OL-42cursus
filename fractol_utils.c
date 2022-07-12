/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:08:23 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 02:54:53 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * ft_pow(base, --exp));
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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		close_window(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	exit(0);
	return (0);
}
