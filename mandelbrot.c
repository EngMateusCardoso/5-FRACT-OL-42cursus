/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:10:06 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 05:27:06 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_grau2(double x, double y)
{
	double	zx;
	double	zy;
	double	temp;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = zx * zx - zy * zy + x;
		zy = 2 * temp * zy + y;
		i++;
	}
	return (i);
}

int	mandelbrot_grau3(double x, double y)
{
	double	zx;
	double	zy;
	double	temp;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = zx * zx * zx - 3 * zx * zy * zy + x;
		zy = -zy * zy * zy + 3 * temp * temp * zy + y;
		i++;
	}
	return (i);
}

int	mandelbrot_grau4(double x, double y)
{
	double	zx;
	double	zy;
	double	temp;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = pow(zx, 4) - 6 * zx * zx * zy * zy + pow(zy, 4) + x;
		zy = 4 * pow(temp, 3) * zy - 4 * pow(zy, 3) * temp + y;
		i++;
	}
	return (i);
}

int	mandelbrot_grau5(double x, double y)
{
	double	zx;
	double	zy;
	double	temp;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = pow(zx, 5) - 10 * pow(zx, 3) * zy * zy + 5 * zx * pow(zy, 4) + x;
		zy = 5 * pow(zx, 4) * zy - 10 * zx * zx * pow(zy, 3) + pow(zy, 5) + y;
		zx = temp;
		i++;
	}
	return (i);
}

int	mandelbrot(double x, double y, t_img *img)
{
	int	i;

	i = 0;
	if (img->type == 2)
		i = mandelbrot_grau2(x, y);
	else
	{
		if (img->grau == '3')
			i = mandelbrot_grau3(x, y);
		else if (img->grau == '4')
			i = mandelbrot_grau4(x, y);
		else if (img->grau == '5')
			i = mandelbrot_grau5(x, y);
	}
	return (i);
}
