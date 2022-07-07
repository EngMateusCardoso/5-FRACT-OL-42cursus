/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:57:22 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/24 20:20:59 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*target;
	t_list	*elem;

	target = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
			ft_lstclear(&elem, del);
		else
			ft_lstadd_back(&target, elem);
		lst = lst->next;
	}
	return (target);
}
