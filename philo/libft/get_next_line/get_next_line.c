/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:40 by dtoure            #+#    #+#             */
/*   Updated: 2022/11/10 18:25:48 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_lines(char *lines)
{
	size_t	i;
	size_t	j;
	char	*new_lines;

	new_lines = NULL;
	i = 0;
	j = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i])
	{
		new_lines = ft_callocs(((ft_strlens(lines) - i + 1)), sizeof(char));
		if (!new_lines)
			return (NULL);
		if (lines[i] == '\n')
			i++;
		while (lines[i + j])
		{
			new_lines[j] = lines[i + j];
			j++;
		}
	}
	free(lines);
	return (new_lines);
}

char	*ft_strchrs(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!c)
		return ((char *)(s) + ft_strlens(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_lines(char *lines, char *buffer, int ret, int fd)
{
	while (ret && !ft_strchrs(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buffer[ret] = '\0';
		lines = ft_strjoins(lines, buffer, ret);
		if (!lines)
			return (NULL);
	}
	return (lines);
}

char	*ft_getlines(char *lines)
{
	size_t	i;
	char	*new_lines;

	i = 0;
	if (!(*lines))
		return (NULL);
	while (lines[i] && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	new_lines = ft_callocs((i + 1), sizeof(char));
	if (!new_lines)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
	{
		new_lines[i] = lines[i];
		i++;
	}
	if (lines[i] == '\n')
		new_lines[i++] = '\n';
	new_lines[i] = 0;
	return (new_lines);
}

char	*get_next_line(int fd, int last)
{
	char		*buffer;
	static char	*lines;
	char		*res;

	if (!last)
	{
		free(lines);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = ft_callocs((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	lines = ft_lines(lines, buffer, 1, fd);
	res = ft_getlines(lines);
	lines = next_lines(lines);
	free(buffer);
	return (res);
}
