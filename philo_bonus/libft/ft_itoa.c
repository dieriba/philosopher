/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:10:50 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:10:50 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
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

char	*ft_itoa(int n)
{
	int				i;
	int				j;
	unsigned int	nb;
	char			*str;

	nb = -(n < 0) * (n) + (n > 0) * (n);
	i = (n < 0);
	j = ft_nblen(n);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[j] = 0;
	while (--j >= i)
	{
		str[j] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
