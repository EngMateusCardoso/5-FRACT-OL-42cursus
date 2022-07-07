/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:31:57 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/22 06:57:37 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*target;

	len = ft_strlen(src) + 1;
	target = (char *)ft_calloc(len, sizeof(char));
	if (target)
		ft_strlcpy(target, src, len);
	return (target);
}
