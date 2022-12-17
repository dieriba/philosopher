/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:11:54 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:11:54 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;
	size_t	i;

	i = -1;
	if (!src && !dest)
		return (NULL);
	if (!n)
		return (dest);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (dest > src)
		while (n--)
			*(tmp_dest + n) = *(tmp_src + n);
	else if (dest < src)
		while (++i < n)
			*(tmp_dest + i) = *(tmp_src + i);
	return (dest);
}
