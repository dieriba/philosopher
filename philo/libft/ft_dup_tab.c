/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:16:59 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 15:04:25 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_tab(char **to_copy, char *to_join)
{
	size_t	i;
	char	**tab;

	if (!to_copy || !to_join)
		return (NULL);
	i = ft_tab_len(to_copy);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = 0;
	i = -1;
	while (to_copy[++i])
	{
		tab[i] = ft_strjoin(to_copy[i], to_join);
		if (!tab[i])
			return (ft_free_tab(tab));
	}
	ft_free_tab(to_copy);
	return (tab);
}
