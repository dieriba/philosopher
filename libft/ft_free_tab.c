/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:13:26 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/23 14:46:38 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}
