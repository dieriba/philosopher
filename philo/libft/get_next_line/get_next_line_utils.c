/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:21 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 16:09:21 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlens(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzeros(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = 0;
}

char	*ft_callocs(size_t nmemb, size_t size)
{
	char	*buff;

	buff = malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzeros(buff, (size * nmemb));
	return (buff);
}

void	*ft_memcpys(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoins(char *s1, char *s2, size_t len)
{
	size_t	i;
	char	*buff;

	if (!s1)
		s1 = ft_callocs(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlens(s1);
	buff = malloc(sizeof(char) * (i + len + 1));
	if (!buff)
		return (NULL);
	ft_memcpys(buff, s1, i);
	ft_memcpys(buff + i, s2, (len + 1));
	free(s1);
	return (buff);
}
