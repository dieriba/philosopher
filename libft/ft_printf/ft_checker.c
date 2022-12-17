/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:14:42 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:14:42 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_valid(const char *base, char c)
{
	size_t	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int	valid_format(const char *format)
{
	size_t	i;
	char	*str;

	str = (char *)format;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == '%' && ft_valid(BASE_FORMAT, str[++i])))
			return (1);
		i++;
	}
	return (0);
}
