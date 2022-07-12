/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:41:47 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 21:49:11 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_mono(double x, double y, int i, t_img *img)
{
	int	color;
	int	increment;

	color = BLACK;
	if (i < MAX_ITER)
	{
		i = ((i / img->range) * img->range) * 32;
		if (img->color == RED)
			increment = i | i << 8;
		else if (img->color == GREEN)
			increment = i | i << 16;
		else
			increment = i << 16 | i << 8;
		color = img->color | increment;
	}
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}

void	set_color_vibrant(double x, double y, int i, t_img *img)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (((i / img->range) * img->range) % 5 == 1)
		color = 0x00FF0FE3;
	else if (((i / img->range) * img->range) % 5 == 2)
		color = 0x00FF4F5E;
	else if (((i / img->range) * img->range) % 5 == 3)
		color = 0x00FFDE21;
	else if (((i / img->range) * img->range) % 5 == 4)
		color = 0x00FAFF92;
	else if (((i / img->range) * img->range) % 5 == 0)
		color = 0x007EFFF8;
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}

void	set_color_vintage(double x, double y, int i, t_img *img)
{
	int	color;

	color = 0x00000000;
	if (i == 100)
		color = 0x00000000;
	else if (((i / img->range) * img->range) % 5 == 1)
		color = 0x00EFD9B4;
	else if (((i / img->range) * img->range) % 5 == 2)
		color = 0x00D6A692;
	else if (((i / img->range) * img->range) % 5 == 3)
		color = 0x00A39081;
	else if (((i / img->range) * img->range) % 5 == 4)
		color = 0x004D6160;
	else if (((i / img->range) * img->range) % 5 == 0)
		color = 0x00292522;
	my_mlx_pixel_put(img, x / img->pass - img->xmin / img->pass, \
	y / img->pass - img->ymin / img->pass, color);
}

void	set_color(double x, double y, int i, t_img *img)
{
	if (img->color == BLUE || img->color == GREEN || img->color == RED)
		set_color_mono(x, y, i, img);
	else if (img->color == 1)
		set_color_vibrant(x, y, i, img);
	else if (img->color == -1)
		set_color_vintage(x, y, i, img);
}
