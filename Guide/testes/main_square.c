# include "../minilibx-linux/mlx.h"
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

	mlx = mlx_init();
	if (mlx == NULL)
		return(MLX_ERROR);
	win_ptr = mlx_new_window(mlx, 800, 500, "Hello world!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return(MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,&img.endian);
	x = 350;
	while (x <= 450)
	{
		y = 200;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y = 300;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
	}
	while (y >= 200)
	{
		x = 350;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x = 450;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y--;
	}

	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
	mlx_loop(mlx);
}
