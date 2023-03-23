/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:18:23 by repinat           #+#    #+#             */
/*   Updated: 2021/11/30 17:01:15 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!lst)
		{
			ft_lstclear(&new, del);
			new->next = 0;
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
