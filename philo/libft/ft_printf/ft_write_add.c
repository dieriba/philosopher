/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:30 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:15:30 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	get_len(unsigned long int n)
{
	unsigned long int	len;

	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len *= 16;
	}
	return (len);
}

int	ft_write_hex_adress(unsigned long int nbr, int *count)
{
	int					val;
	char				*base;
	char				c;
	unsigned long int	len;

	base = "0123456789abcdef";
	if (nbr == 0 && !(*(count)))
	{
		write(1, "(nil)", 5);
		return (5);
	}
	val = 2;
	len = get_len(nbr);
	write(1, "0x", 2);
	while (len != 0)
	{
		c = base[(nbr / len)];
		ft_putchar(c);
		nbr %= len;
		len /= 16;
		val++;
	}
	if (!*(count))
		*count = val;
	return (*count);
}
