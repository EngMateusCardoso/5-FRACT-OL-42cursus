
#include "fractol.h"

int handle_input(int keysys, t_win *win)
{
    win->img.pass = (win->img.xmax-win->img.xmin)/WIN_SIDE;
    if (keysys == 65307)
        close_window(win);
    else if (keysys == 65361)
    {
        win->img.xmin -= 10 * win->img.pass;
        win->img.xmax -= 10 * win->img.pass;
    }
    else if (keysys == 65362)
    {
        win->img.ymin -= 10 * win->img.pass;
        win->img.ymax -= 10 * win->img.pass;
    }
    else if (keysys == 65363)
    {
        win->img.xmin += 10 * win->img.pass;
        win->img.xmax += 10 * win->img.pass;
    }
    else if (keysys == 65364)
    {
        win->img.ymin += 10 * win->img.pass;
        win->img.ymax += 10 * win->img.pass;
    }
    start_image(win);
    return (0);
}

void    mouse_pan(t_win *win, int x, int y)
{
    win->img.pass = (win->img.xmax-win->img.xmin)/WIN_SIDE;
    win->img.xmin += (x - 250) * win->img.pass;
    win->img.xmax += (x - 250) * win->img.pass;
    win->img.ymin += (y - 250) * win->img.pass;
    win->img.ymax += (y - 250) * win->img.pass;
}

int     zoom(int keysys, int x, int y, t_win *win)
{
    float   range;

    range = win->img.xmax-win->img.xmin;
    if (keysys == 4)
    {
        win->img.xmin += 0.1*range;
        win->img.xmax -= 0.1*range;
        win->img.ymin += 0.1*range;
        win->img.ymax -= 0.1*range;
    }
    if (keysys == 5)
    {
        win->img.xmin -= 0.1*range;
        win->img.xmax += 0.1*range;
        win->img.ymin -= 0.1*range;
        win->img.ymax += 0.1*range;
    }
    mouse_pan(win, x, y);
    start_image(win);
    return (0);
}
