/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:37:40 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 15:26:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static int	check_ascii(char c)
{
	if (c == '|')
		return (1);
	else if (c == '\'' || c == '\"')
		return (2);
	else if (c == '>' || c == '<')
		return (3);
	else if (c == '&')
		return (4);
	else if (c == '(')
		return (5);
	else if (c == ' ')
		return (6);
	return (0);
}

static int	do_ft_split_syntax(char ***temp, char **buff, char *s, int i)
{
	int	check;

	check = check_ascii(s[i]);
	if (check == 0)
		*buff = ft_strcjoin(*buff, s[i]);
	else
	{
		if (*buff != NULL)
			*temp = ft_strsjoin(*temp, *buff);
		*buff = NULL;
		if (check == 1)
			i += ft_split_pipe(temp, s, i);
		else if (check == 2)
			i += ft_split_quote(temp, s, i);
		else if (check == 3)
			i += ft_split_redirection(temp, s, i);
		else if (check == 4)
			i += ft_split_and(temp, s, i);
		else if (check == 5)
			i += ft_split_par(temp, s, i);
	}
	return (i);
}

char	**ft_split(char *s)
{
	char	**temp;
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	temp = NULL;
	while (s[i])
	{
		i = do_ft_split_syntax(&temp, &buff, s, i);
		if (s[i] != '\0')
			i++;
	}
	if (buff != NULL)
		temp = ft_strsjoin(temp, buff);
	if (temp == NULL && buff == NULL)
		return (NULL);
	return (temp);
}
