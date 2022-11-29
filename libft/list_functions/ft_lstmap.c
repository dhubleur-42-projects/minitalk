/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:35:35 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/24 11:49:54 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newlist_first;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	newlist_first = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		newlist->next = ft_lstnew((*f)(lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&newlist_first, del);
			return (NULL);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (newlist_first);
}
