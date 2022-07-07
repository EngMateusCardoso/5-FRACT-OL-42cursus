/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:48:52 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/23 06:21:28 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*put_slices(char const *s, char c, int n_str)
{
	int		count_str;
	int		start;
	int		end;
	char	*str;

	end = 0;
	count_str = 0;
	while (s[end] && count_str <= n_str)
	{
		if (s[end] != c && s[end])
		{
			start = end;
			count_str++;
			while (s[end] != c && s[end])
				end++;
		}
		else
			end++;
	}
	str = (char *)malloc((end - start + 1) * sizeof(char));
	ft_strlcpy((char *)str, (char *)(s + start), (size_t)(end - start + 1));
	return (str);
}

unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count_strs;

	i = 0;
	count_strs = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count_strs++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count_strs);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count_strs;
	unsigned int	count_str;
	char			**split;

	if (!s)
		return (NULL);
	count_strs = ft_countwords(s, c);
	split = (char **)malloc(++count_strs * sizeof(char *));
	if (!split)
		return (NULL);
	count_str = 0;
	while (count_str < count_strs - 1)
	{
		split[count_str] = put_slices(s, c, count_str);
		count_str++;
	}
	split[count_str] = NULL;
	return (split);
}
