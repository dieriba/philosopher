/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:09 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:12:09 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr > 9)
		ft_putnbr_fd((nbr / 10), fd);
	if (ft_putchar_fd((nbr % 10) + '0', fd) < 0)
		exit(EXIT_FAILURE);
}
