/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:11:09 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:11:09 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (!(*lst) || !(*del))
		return ;
	curr = *(lst);
	while (curr)
	{
		(*del)(curr -> content);
		tmp = curr -> next;
		free(curr);
		curr = tmp;
	}
	*(lst) = NULL;
}
