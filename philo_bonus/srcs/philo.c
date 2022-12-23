/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:03 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:03 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	dinner_info;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd(WRONG_ARGS, 2);
		return (1);
	}
	initialization(&dinner_info, argc, argv);
	forking(&dinner_info);
	return (0);
}
