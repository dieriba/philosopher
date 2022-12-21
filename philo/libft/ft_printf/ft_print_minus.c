/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:14:55 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:14:55 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_uns(va_list args_infos, int num, char c)
{
	unsigned int	format_num_uns;
	int				len;
	va_list			args_infos_cpy;
	int				base;

	if (c == 'u')
		base = 10;
	else
		base = 16;
	va_copy(args_infos_cpy, args_infos);
	format_num_uns = (unsigned int)va_arg(args_infos_cpy, unsigned int);
	va_end(args_infos_cpy);
	len = 0;
	while (format_num_uns != 0)
	{
		format_num_uns /= base;
		len++;
	}
	if (len < num)
		ft_print_char(num - len, 'x');
	else if (len >= num && len != 0)
		return (len);
	return (num);
}

static int	get_int(va_list args_infos, int num)
{
	int		format_num;
	int		len;
	va_list	args_infos_cpy;
	int		is_neg;

	va_copy(args_infos_cpy, args_infos);
	format_num = (int)va_arg(args_infos_cpy, int);
	is_neg = -(format_num < 0);
	va_end(args_infos_cpy);
	len = (format_num < 0);
	while (format_num != 0)
	{
		format_num /= 10;
		len++;
	}
	if (is_neg < 0)
		ft_putchar('-');
	if (len < num)
		ft_print_char(num - len, '0');
	else if (len >= num && len != 0)
		return (len);
	return (num);
}

int	ft_print_minus(const char *format, va_list args_infos, size_t *i)
{
	char	*str;
	int		num;
	size_t	tmp;

	tmp = *i;
	num = 0;
	str = (char *)format;
	while (str[++tmp] && ft_isdigit(str[tmp]))
		num = num * 10 + (str[tmp] - '0');
	if (str[tmp] && !ft_valid(BASE_FORMAT, str[tmp]))
		num = 0;
	else
	{
		*i = tmp;
		if (str[tmp] != 'u' && str[tmp] != 'x' && str[tmp] != 'X')
			num = get_int(args_infos, num);
		else
			num = get_uns(args_infos, num, str[tmp]);
	}
	return (num);
}
