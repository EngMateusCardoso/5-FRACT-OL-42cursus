/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:52:07 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/22 05:56:13 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	count_big;
	size_t	count_little;

	count_big = 0;
	count_little = 0;
	if (!(*little))
		return ((char *)big);
	while (big[count_big] && count_big < len)
	{
		while (big[count_big + count_little] == little[count_little]
			&& little[count_little] && count_big + count_little < len)
		{
			count_little++;
			if (!(little[count_little]))
				return ((char *)&big[count_big]);
		}
		count_little = 0;
		count_big++;
	}
	return (NULL);
}
