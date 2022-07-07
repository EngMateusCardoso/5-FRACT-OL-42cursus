/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:52:55 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/27 05:20:28 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_base(int n)
{
	if (n <= 9 && n >= -9)
		return (1);
	return (ft_count_base(n / 10) * 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_iter;
	int			base;

	n_iter = n;
	base = ft_count_base(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_iter *= -1;
	}
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(n + '0', fd);
		n_iter -= base * n;
		base = base / 10;
	}
}
