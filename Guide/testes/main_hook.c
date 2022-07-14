# include "../../minilibx-linux/mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
    if (keycode == 65307)
	    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

/* int	mouse(int keycode, t_vars *vars)
{
    if (keycode == 1)
        write(1, "click\n", 6);
    else if (keycode == 3)
        write(1, "inverse\n", 8);
    else if (keycode == 4)
        write(1, "up\n", 3);
    else if (keycode == 5)
        write(1, "down\n", 3);
	return (0);
} */

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
    //mlx_mouse_hook(vars.win, mouse, &vars);
    //mlx_key_hook(vars.win, close, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}