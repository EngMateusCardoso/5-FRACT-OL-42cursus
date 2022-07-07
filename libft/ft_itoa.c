/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:24:18 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/27 08:02:43 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countbase(int n)
{
	if (n <= 9 && n >= -9)
		return (1);
	return (ft_countbase(n / 10) * 10);
}

size_t	ft_intlen(int n)
{
	if (n <= 9 && n >= -9)
	{
		if (n < 0)
			return (2);
		return (1);
	}
	return (ft_intlen(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			base;
	long int	n_iter;

	len = ft_intlen(n);
	base = ft_countbase(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	n_iter = n;
	if (n < 0)
	{
		str[ft_strlen(str)] = (char) '-';
		n_iter *= -1;
	}
	while (base >= 1)
	{
		n = n_iter / base;
		str[ft_strlen(str)] = (char)(n + '0');
		n_iter -= base * n;
		base /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
