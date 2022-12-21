/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:13:14 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:13:14 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_charset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*buff;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_is_in_charset(set, s1[i]))
		i++;
	while (j > i && ft_is_in_charset(set, s1[j]))
		j--;
	buff = malloc(sizeof(char) * (j - i + 2));
	if (!buff)
		return (NULL);
	ft_memcpy(buff, s1 + i, (j - i + 1));
	buff[j - i + 1] = 0;
	return (buff);
}
