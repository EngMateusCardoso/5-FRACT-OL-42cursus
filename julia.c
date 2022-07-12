/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:42:01 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 06:41:03 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia2(double x, double y, t_img *img)
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
		zx = zx * zx - zy * zy + img->julia_x;
		zy = 2 * temp * zy + img->julia_y;
		i++;
	}
	return (i);
}

int	julia3(double x, double y, t_img *img)
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
		zx = zx * zx * zx - 3 * zx * zy * zy + img->julia_x;
		zy = -zy * zy * zy + 3 * temp * temp * zy + img->julia_y;
		i++;
	}
	return (i);
}

int	julia4(double x, double y, t_img *img)
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
		zx = pow(zx, 4) - 6 * zx * zx * zy * zy + pow(zy, 4) + img->julia_x;
		zy = 4 * pow(temp, 3) * zy - 4 * pow(zy, 3) * temp + img->julia_y;
		i++;
	}
	return (i);
}

int	julia5(double x, double y, t_img *img)
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
		temp = pow(zx, 5) - 10 * pow(zx, 3) * zy * zy + 5 * zx * pow(zy, 4);
		zy = 5 * pow(zx, 4) * zy - 10 * zx * zx * pow(zy, 3) + pow(zy, 5);
		zx = temp + img->julia_x;
		zy += img->julia_y;
		i++;
	}
	return (i);
}

int	julia(double x, double y, t_img *img)
{
	int	i;

	i = 0;
	if (img->type == 4)
		i = julia2(x, y, img);
	else
	{
		if (img->grau == '3')
			i = julia3(x, y, img);
		else if (img->grau == '4')
			i = julia4(x, y, img);
		else if (img->grau == '5')
			i = julia5(x, y, img);
	}
	return (i);
}
