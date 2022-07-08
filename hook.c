
#include "fractol.h"

int handle_input(int keysys, t_win *win)
{
        if (keysys == 65307)
        close_window(win);
	else if (keysys == 65361)
        write(1, "lf\n", 3);
	else if (keysys == 65362)
        write(1, "up\n", 3);
	else if (keysys == 65363)
        write(1, "rg\n", 3);
	else if (keysys == 65364)
        write(1, "dw\n", 3);
	return (0);
}

int	zoom(int keysys, int x, int y)
{
    if (keysys == 4)
        write(1, "up\n", 3);
    else if (keysys == 5)
        write(1, "dw\n", 3);
    printf(" %d %d\n", x, y);
        return (0);
}
