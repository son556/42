/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:28:41 by chanson           #+#    #+#             */
/*   Updated: 2023/01/13 19:30:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

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

	buffer_cnt = get_strllen(buffer + idx);
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
	if (get_strllen(buffer) > 0)
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
		idx = get_strchr(buffer, '\n');
		if (idx != -1)
		{
			*line = get_strdup(buffer, idx);
			buffer = remake_buffer(buffer, idx + 1);
			return (buffer);
		}
		cnt = read(fd, temp, BUFFER_SIZE);
		if (cnt < 0)
			break ;
		temp[cnt] = '\0';
		buffer = get_strjoin(buffer, temp);
	}
	if (cnt > -1)
		*line = get_strdup(buffer, get_strchr(buffer, '\0'));
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
	if (get_strllen(buffer) > 0)
		buffer = make_line(buffer, &line, fd, temp);
	else
	{
		cnt = read(fd, temp, BUFFER_SIZE);
		if (cnt <= 0)
			free(temp);
		if (cnt <= 0)
			return (0);
		temp[cnt] = '\0';
		buffer = get_strdup(temp, get_strchr(temp, '\0'));
		buffer = make_line(buffer, &line, fd, temp);
	}
	free_pointer(temp);
	return (line);
}
