/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:14:53 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:14:53 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hash(const char *format, va_list args_infos, size_t *i)
{
	char			*str;
	size_t			tmp;
	unsigned int	format_num;
	va_list			args_infos_cpy;

	str = (char *)format;
	tmp = *i;
	va_copy(args_infos_cpy, args_infos);
	format_num = (unsigned int)va_arg(args_infos_cpy, unsigned int);
	va_end(args_infos_cpy);
	if (str[++tmp] && (str[tmp] == 'x' || str[tmp] == 'X'))
	{
		*i = tmp;
		if (!format_num)
			return (0);
		if (str[tmp] && (str[tmp] == 'x'))
			ft_putstr_fd("0x", 1);
		else if (str[tmp])
			ft_putstr_fd("0X", 1);
		return (ft_getlen(format_num) + 2);
	}
	return (0);
}
