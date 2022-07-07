/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:16:01 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/20 19:02:31 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cont;

	if (!dest && !src)
		return (NULL);
	cont = -1;
	if (dest > src)
		ft_memcpy(dest, src, n);
	else
		while (cont++ + 1 < n)
			*(char *)(dest + cont) = *(char *)(src + cont);
	return (dest);
}
