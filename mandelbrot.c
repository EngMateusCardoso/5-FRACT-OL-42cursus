
#include "fractol.h"


void	set_color_mandelbrot(float x, float y, int i, t_img img)
{
	int color;

	color = 0x00000000;
	if (i < 1)
		color = 0x00F03C02;
	else if (i < 2)
		color = 0x00C21A01;
	else if (i < 4)
		color = 0x00A30006;
	else if (i < 8)
		color = 0x006B0103;
	else if (i < 16)
		color = 0x001C0113;
	my_mlx_pixel_put(&img, x*(WIN_SIDE/(img.xmax-img.xmin))-(WIN_SIDE*img.xmin/(img.xmax-img.xmin)), y*(WIN_SIDE/(img.xmax-img.xmin))-(WIN_SIDE*img.ymin/(img.xmax-img.xmin)), color);
}

void	set_color_mandelbrot2(float x, float y, int i, t_img img)
{
	int color;

	color = 0x00000000;
	if (i < 1)
		color = 0x00EFD9B4;
	else if (i < 2)
		color = 0x00D6A692;
	else if (i < 4)
		color = 0x00A39081;
	else if (i < 8)
		color = 0x004D6160;
	else if (i < 16)
		color = 0x00292522;
	my_mlx_pixel_put(&img, x/img.pass-img.xmin/img.pass, y/img.pass-img.ymin/img.pass, color);
}

int		mandelbrot_iter(float x,float y)
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
}

void    mandelbrot(t_img	img)
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
			i = mandelbrot_iter(x, y);
			set_color_mandelbrot(x, y, i, img);
			y += img.pass;
		}
		x += img.pass;
	}
}
