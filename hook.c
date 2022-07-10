/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:08:38 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/10 02:20:55 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(int keysys, t_win *win)
{
	if (keysys == 114)
		win->img.color = RED;
	else if (keysys == 103)
		win->img.color = GREEN;
	else if (keysys == 98)
		win->img.color = BLUE;
	else if (keysys == 44)
		win->img.range += 1;
	else if (keysys == 46)
	{
		if (win->img.range > 1)
			win->img.range -= 1;
	}
}

int 	handle_input(int keysys, t_win *win)
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
	else if (keysys == 114 || keysys == 103 || keysys == 98 || keysys == 44 || keysys == 46)
		change_color(keysys, win);
	start_image(win);
	return (0);
}

void	mouse_pan(t_win *win, int x, int y)
{
	win->img.pass = (win->img.xmax-win->img.xmin)/WIN_SIDE;
	win->img.xmin += (x - 250) * win->img.pass;
	win->img.xmax += (x - 250) * win->img.pass;
	win->img.ymin += (y - 250) * win->img.pass;
	win->img.ymax += (y - 250) * win->img.pass;
}

int		zoom(int keysys, int x, int y, t_win *win)
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
