/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:00 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:15:00 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int(va_list args_infos, int num)
{
	int		is_neg;
	int		len;
	int		format_num;
	va_list	args_infos_cpy;

	va_copy(args_infos_cpy, args_infos);
	format_num = (int)va_arg(args_infos_cpy, int);
	len = (format_num == 0);
	is_neg = -(format_num < 0);
	va_end(args_infos_cpy);
	if (is_neg < 0)
		ft_putchar('-');
	else
		ft_putchar(' ');
	while (format_num)
	{
		format_num /= 10;
		len++;
	}
	return (num + len);
}

int	ft_print_space(const char *format, va_list args_infos, size_t *i)
{
	char	*str;
	int		num;
	size_t	tmp;

	tmp = *i;
	num = 1;
	str = (char *)format;
	while (str[tmp] && (str[tmp] == ' '))
		tmp++;
	*i = tmp;
	if (!str[tmp] || !ft_valid("id", str[tmp]))
		return (0);
	num = get_int(args_infos, num);
	return (num);
}
