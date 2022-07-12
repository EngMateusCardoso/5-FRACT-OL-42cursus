/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:10:06 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 03:04:53 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_mandelbrot(float x, float y, int i, t_img img)
{
	int	color;
	int	increment;

	color = BLACK;
	if (i < MAX_ITER)
	{
		if (img.color == RED)
		{
			increment = ((i/img.range)*img.range) * 16;
			increment += ((i/img.range)*img.range) * 16  << 8;
		}
		else if (img.color == GREEN)
		{
			increment = ((i/img.range)*img.range) * 16;
			increment += ((i/img.range)*img.range) * 16  << 16;
		}
		else
		{
			increment = ((i/img.range)*img.range) * 16 << 16;
			increment += ((i/img.range)*img.range) * 16  << 8;
		}
		color = img.color + increment;
	}
	my_mlx_pixel_put(&img, x/img.pass-img.xmin/img.pass, y/img.pass-img.ymin/img.pass, color);
}

void	set_color_mandelbrotback(float x, float y, int i, t_img img)
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
	my_mlx_pixel_put(&img, x/img.pass-img.xmin/img.pass, y/img.pass-img.ymin/img.pass, color);
}

/* int		mandelbrot(float x,float y)
{
	float	zx;
	float	zy;
	float	temp;
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
} */

int		mandelbrot(float x,float y)
{
	float	zx;
	float	zy;
	float	temp;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = zx * zx *zx - 3 * zx * zy * zy + x;
		zy = - zy * zy * zy + 3 * temp * temp * zy + y;
		i++;
	}
	return (i);
}

/*int		mandelbrot(float x,float y)
{
	float	zx;
	float	zy;
	float	temp;
	int		i;

	i = 0;
	zx = ((x*x) - (y*y))/((((x*x) - (y*y))*((x*x) - (y*y)))-((2*x*y)*(2*x*y)));
	zy = (-2*x*y)/((((x*x) - (y*y))*((x*x) - (y*y)))-((2*x*y)*(2*x*y))) ;
	x = zx;
	y = zy;
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = sinh(zx)*cos(zy) + x;
		zy = cosh(temp)*sin(zy)+ y;
		i++;
	}
	return (i);
}*/

/*int		mandelbrot(float x,float y)
{
	float	zx;
	float	zy;
	float	temp;
	int		i;

	i = 0;
	zx = cosh(y)*sin(x) + 0.1*sinh(y)*cos(x);
	zy = sinh(y)*cos(x) - 0.1*cosh(y)*sin(x);
	while ((zx * zx) + (zy * zy) <= 4 && i < MAX_ITER)
	{
		temp = zx;
		zx = cosh(zy)*sin(zx) + 0.1*sinh(zy)*cos(zx);
		zy = sinh(zy)*cos(temp) - 0.1*cosh(zy)*sin(temp);
		i++;
	}
	return (i);
}*/

int		julia(float x,float y, t_img *img)
{
	float	zx;
	float	zy;
	float	temp;
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

void	fractal(t_img img)
{
	float	x;
	float	y;
	int		i;

	img.pass = (img.xmax-img.xmin)/WIN_SIDE;
	x = img.xmin;
	while (x <= img.xmax)
	{
		y = img.ymin;
		while (y <= img.ymax)
		{
			if (img.type == 2)
				i = mandelbrot(x, y);
			else if (img.type == 4)
				i = julia(x, y, &img);
			set_color_mandelbrot(x, y, i, img);
			y += img.pass;
		}
		x += img.pass;
	}
}
