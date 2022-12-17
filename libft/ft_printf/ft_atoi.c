/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:14:39 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/11 18:14:39 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *format, int *pos)
{
	char	*str;
	int		num;
	int		i;

	i = *pos;
	num = 0;
	str = (char *)format;
	while (str[++i] && ft_isdigit(str[i]))
		num = num + str[i] - '0';
	return (num);
}
