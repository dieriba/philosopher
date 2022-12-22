/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:57:59 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 04:03:16 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buf;

	if (!s || !n)
		return ;
	i = -1;
	buf = (char *) s;
	while (++i < n)
		buf[i] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*buff;

	if (!size || !nmemb)
		return (NULL);
	buff = malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (size * nmemb));
	return (buff);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	if (dest == NULL || src == NULL)
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

int	ft_nblen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = (n < 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
