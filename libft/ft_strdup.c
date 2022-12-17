/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:26 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:12:26 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buff)
		return (NULL);
	while (s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = 0;
	return (buff);
}
