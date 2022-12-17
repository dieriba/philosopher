/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:11:46 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:11:46 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff_1;
	unsigned char	*buff_2;

	i = 0;
	buff_1 = (unsigned char *)s1;
	buff_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (buff_1[i] != buff_2[i])
			return (buff_1[i] - buff_2[i]);
		i++;
	}
	return (0);
}
