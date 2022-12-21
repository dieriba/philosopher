/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:07:04 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/08 14:07:04 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*buff;

	if (!size || !nmemb)
		return (NULL);
	buff = malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (size * nmemb));
	return (buff);
}
