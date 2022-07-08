
#include "fractol.h"

int handle_input(int keysys, t_win *win)
{
	if (keysys == 65307)
        close_window(win);
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
