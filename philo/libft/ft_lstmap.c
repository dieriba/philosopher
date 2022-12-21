/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:11:30 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:11:30 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*head;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	n_lst = ft_lstnew((*f)(lst -> content));
	head = n_lst;
	lst = lst -> next;
	while (lst != NULL)
	{
		n_lst -> next = ft_lstnew((*f)(lst -> content));
		if (!(n_lst -> next))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst -> next;
		n_lst = n_lst -> next;
	}
	return (head);
}
