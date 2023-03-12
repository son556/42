/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:29:59 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 15:21:19 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strchr_gnl(const char *s, int c);
char	*ft_strchr_s_gnl(const char *s, int c);
char	*get_next_line_gnl(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strllen_gnl(char const *s);
char	*ft_strdup_gnl(const char *s1, int end);
void	free_pointer_gnl(char *ptr);
char	*get_next_line(int fd);
#endif