
#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	set_color_mandelbrot(float x, float y, int i, t_img img)
{
	if (i < 1)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00F03C02);
	else if (i < 2)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00C21A01);
	else if (i < 4)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00A30006);
	else if (i < 8)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x006B0103);
	else if (i < 16)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x001C0113);
}

void	set_color_mandelbrot2(float x, float y, int i, t_img img)
{
	if (i < 1)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00EFD9B4);
	else if (i < 2)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00D6A692);
	else if (i < 4)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00A39081);
	else if (i < 8)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x004D6160);
	else if (i < 16)
		my_mlx_pixel_put(&img, x*(WIN_WIDTH/4)+(WIN_WIDTH/2), y*(WIN_HEIGHT/4)+(WIN_HEIGHT/2), 0x00292522);
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
	while ((zx * zx) + (zy * zy) <= 4 && i < 500)
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
	float	x_pass;
	float	y_pass;
	int		i;

	x_pass = 0.005;
	y_pass = 0.005;
	x = -2;
	while (x <= 2)
	{
		y = -2;
		while (y <= 2)
		{
			i = mandelbrot_iter(x, y);
			set_color_mandelbrot2(x, y, i, img);
			y += y_pass;
		}
		x += x_pass;
	}
}
