/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:13:10 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:13:10 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	long int	j;

	i = 0;
	j = -1;
	if (c == 0)
		return ((char *)(s) + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char) c)
			j = i;
		i++;
	}
	if (j > -1)
		return ((char *)(s + j));
	return (NULL);
}
