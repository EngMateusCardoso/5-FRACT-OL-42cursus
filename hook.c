
#include "fractol.h"

int handle_input(int keysys, t_win *win)
{
    if (keysys == 65307)
        close_window(win);
    else if (keysys == 65361)
    {
        win->img.xmin -= 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
        win->img.xmax -= 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
    }
    else if (keysys == 65362)
    {
        win->img.ymin += 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
        win->img.ymax += 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
    }
    else if (keysys == 65363)
    {
        win->img.xmin += 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
        win->img.xmax += 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
    }
    else if (keysys == 65364)
    {
        win->img.ymin -= 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
        win->img.ymax -= 10 * (win->img.xmax-win->img.xmin) / WIN_SIDE;
    }
    start_image(win);
    return (0);
}

int     zoom(int keysys, int x, int y, t_win *win)
{
    if (keysys == 4)
    {
        win->img.xmin *= 0.9;
        win->img.xmax *= 0.9;
        win->img.ymin *= 0.9;
        win->img.ymax *= 0.9;
    }
    if (keysys == 5)
    {
        win->img.xmin *= 1.1;
        win->img.xmax *= 1.1;
        win->img.ymin *= 1.1;
        win->img.ymax *= 1.1;
    }
    start_image(win);
    printf(" %d %d\n", x, y);
    return (0);
}