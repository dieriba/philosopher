/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:11 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:15:11 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_len(unsigned int n, int *count)
{
	unsigned int	len;

	if (*(count) && !n)
		return (0);
	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len *= 16;
	}
	return (len);
}

int	ft_putnbr_base_hex(unsigned int nbr, int transform, int *count)
{
	int				val;
	char			*base;
	char			c;
	unsigned int	len;

	base = "0123456789abcdef";
	val = 0;
	len = get_len(nbr, count);
	while (len != 0)
	{
		if (!transform)
			c = base[(nbr / len)];
		else if ((nbr / len) > 9 && (transform))
		c = base[(nbr / len)] - 32;
		else
		c = base [(nbr / len)];
		ft_putchar(c);
		nbr %= len;
		len /= 16;
		val++;
	}
	if (!*(count))
		*count = val;
	return (*count);
}
