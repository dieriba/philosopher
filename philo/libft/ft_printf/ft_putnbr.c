/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:14 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:15:14 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(long int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len *= 10;
	}
	return (len);
}

int	ft_putnbr(long int n, int *count)
{
	int			len;
	int			val;
	long int	nbr;

	nbr = (long int) n;
	nbr = -(nbr < 0) * nbr + (nbr > 0) * nbr;
	val = (n < 0);
	len = ft_getlen(nbr);
	if (n < 0 && !(*count))
		ft_putchar('-');
	while (len != 0)
	{
		ft_putchar((nbr / len) + '0');
		nbr %= len;
		len /= 10;
		val++;
	}
	if (!(*count))
		*count = val;
	return (*count);
}
