/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:21:11 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/12 02:58:24 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	args_erro(void)
{
	ft_putstr_fd("\nWrong arguments bad request!\n", 1);
	ft_putstr_fd("----------------------------\n", 1);
	ft_putstr_fd("Try something like this:\n\n", 1);
	ft_putstr_fd("./fractol Mandelbrot\n", 1);
	ft_putstr_fd("./fractol Julia X.XXX X.XXX\n", 1);
	ft_putstr_fd("./fractol Multibrot N\n", 1);
	ft_putstr_fd("./fractol Mult-Julia N X.XXX X.XXX\n\n", 1);
	ft_putstr_fd("When, N  = 3 or 4 or 5 and X.XXX any double number.\n", 1);
	ft_putstr_fd("Julia ex.: (0.4, 0.6) (-0.4, -0.6) (0.0, 1.0)\n", 1);
	ft_putstr_fd("\t(0.285, 0.0) (0.285, 0.01) (-0.74, 0.12)\n", 1);
	ft_putstr_fd("\t(-1.312 0.0) (0.37, -0.28) (0.45, 0.1428)\n", 1);
	ft_putstr_fd("\t(-0.70176 -0.3842) (-0.835, -0.2321)\n", 1);
}

int	check_julia_nbr(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	index++;
	if (!(nbr[index] == '.'))
		return (0);
	index++;
	if (!ft_isdigit(nbr[index]))
		return (0);
	while (ft_isdigit(nbr[index]))
		index++;
	if (nbr[index])
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 10))
		return (1);
	else if (argc == 3 && !ft_strncmp("Multibrot", argv[1], 9) \
	&& argv[2][0] >= '3' && argv[2][0] >= '5')
		return (1);
	else if (argc == 4 && !ft_strncmp("Julia", argv[1], 5) \
	&& check_julia_nbr(argv[2]) && check_julia_nbr(argv[3]))
		return (1);
	else if (argc == 5 && !ft_strncmp("Multijulia", argv[1], 10) \
	&& argv[2][0] >= '3' && argv[2][0] >= '5' \
	&& check_julia_nbr(argv[3]) && check_julia_nbr(argv[4]))
		return (1);
	return (0);
}
