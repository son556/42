/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_question.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:09:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/10 18:16:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	get_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*do_itoa(char *arr, int n, int size)
{
	int	minus;

	minus = 1;
	if (n < 0)
	{
		arr[0] = '-';
		minus = -1;
	}
	arr[size] = '\0';
	size--;
	if (n == 0)
	{
		arr[size] = 48;
		return (arr);
	}
	while (n != 0)
	{
		arr[size] = (minus * (n % 10)) + 48;
		n /= 10;
		size--;
	}
	return (arr);
}

char	*value_itoa(int n)
{
	char	*arr;
	int		size;

	size = get_size(n);
	if (n <= 0)
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	arr = do_itoa(arr, n, size);
	return (arr);
}

t_tree	*change_q_mark(t_tree *tree, int value, int flag)
{
	t_env	*tmp;

	tmp = tree->env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, "?"))
			break ;
		tmp = tmp->next;
	}
	free(tmp->value);
	if (flag == 0)
		tmp->value = value_itoa(value);
	else
	{
		if (WIFEXITED(value))
			tmp->value = value_itoa(WEXITSTATUS(value));
		else
			tmp->value = value_itoa(value);
	}
	return (tree);
}
