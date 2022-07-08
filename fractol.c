
#include "fractol.h"

int    start_window(void)
{
	t_win	win;
	t_img	img;

    win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		return(MLX_ERROR);
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_SIDE, WIN_SIDE, "Fract-ol");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		return(MLX_ERROR);
	}
	img.img_ptr = mlx_new_image(win.mlx_ptr, WIN_SIDE, WIN_SIDE);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len,&img.endian);
    mandelbrot(img);
	mlx_mouse_hook(win.win_ptr, zoom, &win);
	mlx_hook(win.win_ptr, 2, 1L<<0, &handle_input, &win);
	mlx_hook(win.win_ptr, 17, 1L<<0, &close_window, &win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(win.mlx_ptr);
    return (0);
}
// mlx_destroy_window(mlx_ptr, win_ptr); and mlx_destroy_display(mlx_ptr);
int main(void)
{
    start_window();
    return (0);
}
