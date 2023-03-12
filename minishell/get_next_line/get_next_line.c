/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:28:41 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 15:05:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_pointer(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

static char	*remake_buffer(char *buffer, int idx)
{
	char	*temp_buffer;
	int		buffer_cnt;
	int		i;

	buffer_cnt = ft_strllen_gnl(buffer + idx);
	if (buffer_cnt > 0)
	{
		temp_buffer = malloc(buffer_cnt + 1);
		i = 0;
		while (buffer[idx])
		{
			temp_buffer[i] = buffer[idx];
			idx++;
			i++;
		}
		free_pointer(buffer);
		temp_buffer[i] = '\0';
		return (temp_buffer);
	}
	if (ft_strllen_gnl(buffer) > 0)
		free_pointer(buffer);
	return (0);
}

char	*make_line(char *buffer, char **line, int fd, char *temp)
{
	int		cnt;
	int		idx;

	cnt = 1;
	while (cnt)
	{
		idx = ft_strchr_gnl(buffer, '\n');
		if (idx != -1)
		{
			*line = ft_strdup_gnl(buffer, idx);
			buffer = remake_buffer(buffer, idx + 1);
			return (buffer);
		}
		cnt = read(fd, temp, BUFFER_SIZE);
		if (cnt < 0)
			break ;
		temp[cnt] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
	}
	if (cnt > -1)
		*line = ft_strdup_gnl(buffer, ft_strchr_gnl(buffer, '\0'));
	free(buffer);
	buffer = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	if (ft_strllen_gnl(buffer) > 0)
		buffer = make_line(buffer, &line, fd, temp);
	else
	{
		cnt = read(fd, temp, BUFFER_SIZE);
		if (cnt <= 0)
			free(temp);
		if (cnt <= 0)
			return (0);
		temp[cnt] = '\0';
		buffer = ft_strdup_gnl(temp, ft_strchr_gnl(temp, '\0'));
		buffer = make_line(buffer, &line, fd, temp);
	}
	free_pointer(temp);
	return (line);
}
