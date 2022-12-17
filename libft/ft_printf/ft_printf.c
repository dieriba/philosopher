/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:33 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:15:33 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counts_flags(const char *format, va_list args_infos, size_t *i, char c)
{
	int	count;

	count = 0;
	if (c == '0')
		count = ft_print_zero(format, args_infos, i);
	else if (c == '-')
		count = ft_print_minus(format, args_infos, i);
	else if (c == '+')
		count = ft_print_plus(format, args_infos, i);
	else if (c == '#')
		count = ft_print_hash(format, args_infos, i);
	else if (c == ' ')
		count = ft_print_space(format, args_infos, i);
	return (count);
}

int	ft_display_format(const char *format, size_t *i, char c, va_list args_infos)
{
	int	count;

	count = ft_counts_flags(format, args_infos, i, c);
	c = (char)format[(*i)];
	if (c == 'c')
		count = ft_putchar((int)va_arg(args_infos, int));
	else if (c == 's')
		count = ft_putstr_fd((char *)va_arg(args_infos, char *), 1);
	else if (c == 'p')
		count = ft_write_hex_adress((unsigned long int)
				va_arg(args_infos, unsigned long int), &count);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr((int)va_arg(args_infos, int), &count);
	else if (c == 'u')
		count = ft_putnbr_uns((unsigned int)
				va_arg(args_infos, unsigned int), &count);
	else if (c == 'x')
		count = ft_putnbr_base_hex((unsigned int)
				va_arg(args_infos, unsigned int), 0, &count);
	else if (c == 'X')
		count = ft_putnbr_base_hex((unsigned int)
				va_arg(args_infos, unsigned int), 1, &count);
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	args_infos;

	va_start(args_infos, format);
	i = 0;
	count = 0;
	while ((char)format[i])
	{
		if ((char)format[i] != '%')
			count += ft_putchar((char)format[i]);
		else
			count += ft_display_format(format, &i,
					(char)format[++i], args_infos);
		i++;
	}
	va_end(args_infos);
	return (count);
}
