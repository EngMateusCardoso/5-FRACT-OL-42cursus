/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:19:56 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/27 07:22:20 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*target;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	target = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (target)
	{
		ft_strlcpy(target, s1, len_s1 + 1);
		ft_strlcat(target, s2, len_s1 + len_s2 + 1);
	}
	return (target);
}
