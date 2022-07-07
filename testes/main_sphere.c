# include "./minilibx-linux/mlx.h"
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
	int		x;
	int		y;
	int		white;
	int		black;

	mlx = mlx_init();
	if (mlx == NULL)
		return(MLX_ERROR);
	win_ptr = mlx_new_window(mlx, 500, 500, "Hello world!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return(MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,&img.endian);
	x = 0;
	white = 0x00FFFFFF;
	black = 0x00000000;
	while (x <= 500)
	{
		y = 0;
		while (y <= 500)
		{
			if ((x - 250) * (x - 250) + (y - 250) * (y - 250) <= 100*100)
				my_mlx_pixel_put(&img, x, y, black);
			else
				my_mlx_pixel_put(&img, x, y, white);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
	mlx_loop(mlx);
}
