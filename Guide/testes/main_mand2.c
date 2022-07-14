# include "../../minilibx-linux/mlx.h"
# include <stdlib.h>
#define MLX_ERROR 1

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
	float	x;
	float	y;
	float	zx;
	float	zy;
	int		white;
	int		black;
	float	pass;
	int		i;
	float	temp;

	mlx = mlx_init();
	if (mlx == NULL)
		return(MLX_ERROR);
	win_ptr = mlx_new_window(mlx, 800, 800, "Mandinho!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return(MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,&img.endian);

	pass = 0.005;
	x = -2;
	i = 0;
	white = 0x00FFFFFF;
	black = 0x00000000;
	while (x <= 2)
	{
		y = -2;
		while (y <= 2)
		{
			zx = x;
			zy = y;
			while (i<= 500 && zx*zx+zy*zy <= 4)
			{
				temp = zx;
				zx = zx*zx-zy*zy+x;
				zy = 2*temp*zy+y;
				i++;
			}
			if (i<=500)
				my_mlx_pixel_put(&img, x*200 + 400, y*200 + 400, black);
			else
				my_mlx_pixel_put(&img, x*200 + 400, y*200 + 400, white);
			i = 0;
			y += pass;
		}
		x += pass;
	}

	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
	mlx_loop(mlx);
}
