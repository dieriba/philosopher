/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:22:27 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 04:50:00 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	str_is_only_digit(int argc, char **argv)
{
	int		i;
	size_t	j;
	char	*str;

	j = -1;
	i = 0;
	while (++i < argc)
	{
		str = argv[i];
		while (str[++j])
			if (!ft_isdigit(str[j]))
				return (0);
		j = -1;
	}
	return (1);
}
