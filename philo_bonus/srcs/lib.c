/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:52:59 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 04:52:47 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	**ft_free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	*ft_itoa(int n)
{
	int				i;
	int				j;
	unsigned int	nb;
	char			*str;

	nb = -(n < 0) * (n) + (n > 0) * (n);
	i = (n < 0);
	j = ft_nblen(n);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[j] = 0;
	while (--j >= i)
	{
		str[j] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	buff = malloc(sizeof(char) * (i + j + 1));
	if (!buff)
		return (NULL);
	ft_memcpy(buff, s1, i);
	ft_memcpy(buff + i, s2, (j + 1));
	return (buff);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (write(fd, str, len) < 0)
		return (-1);
	return (len);
}
