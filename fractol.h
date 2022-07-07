
#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MLX_ERROR 1

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

void    mandelbrot(t_img	img);

#endif
