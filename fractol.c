
#include "fractol.h"

int    start_window(void)
{
    void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;

    mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return(MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Set of Mandelbrot");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return(MLX_ERROR);
	}
	img.img_ptr = mlx_new_image(mlx_ptr, 800, 800);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len,&img.endian);
    mandelbrot(img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
    return (0);
}

int main(void)
{
    start_window();
    return (0);
}
