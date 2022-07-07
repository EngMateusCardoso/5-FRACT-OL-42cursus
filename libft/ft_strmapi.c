/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:36:35 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/24 00:22:54 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*target;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	target = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!target)
		return (NULL);
	i = 0;
	while (s[i])
	{
		target[i] = f(i, s[i]);
		i++;
	}
	target[i] = '\0';
	return (target);
}
