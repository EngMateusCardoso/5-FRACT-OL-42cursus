/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:41:47 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 06:41:54 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_mandelbrot(double x, double y, int i, t_img *img)
{
	int	color;
	int	increment;

	color = BLACK;
	if (i < MAX_ITER)
	{
		if (img->color == RED)
		{
			increment = ((i / img->range) * img->range) * 16;
			increment += ((i / img->range) * img->range) * 16  << 8;
		}
		else if (img->color == GREEN)
		{
			increment = ((i / img->range) * img->range) * 16;
			increment += ((i / img->range) * img->range) * 16  << 16;
		}
		else
		{
			increment = ((i / img->range) * img->range) * 16 << 16;
			increment += ((i / img->range) * img->range) * 16  << 8;
		}
		color = img->color + increment;
	}
	my_mlx_pixel_put(img, x/img->pass-img->xmin/img->pass, y/img->pass-img->ymin/img->pass, color);
}

void	set_color_pretty(double x, double y, int i, t_img *img)
{
	int color;

	color = 0x00000000;
	if (i < 1)
		color = 0x00EFD9B4;
	else if (i < 2)
		color = 0x00D6A692;
	else if (i < 3)
		color = 0x00A39081;
	else if (i < 4)
		color = 0x004D6160;
	else if (i < MAX_ITER)
		color = 0x00292522;
	my_mlx_pixel_put(img, x/img->pass-img->xmin/img->pass, y/img->pass-img->ymin/img->pass, color);
}