/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:31:10 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 04:19:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_algorithm(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	t_greedy	*greedy;
	t_cmd		*cmd_lst;
	int			n;

	greedy = (t_greedy *)malloc(sizeof(t_greedy));
	n = deque_size(deque_a);
	if (!greedy)
		return (0);
	find_pivot(deque_a, greedy);
	cmd_lst = NULL;
	if (n <= 5)
		cmd_lst = make_b_cmd(deque_a, deque_b, greedy);
	else if (n > 5)
	{
		cmd_lst = make_deque_b(deque_a, deque_b);
		so_a(deque_a, deque_b, cmd_lst);
		complete_deque_a(deque_a, greedy, cmd_lst);
	}
	display_cmd(cmd_lst);
	free(greedy);
	ft_cmdclear(&cmd_lst);
	return (1);
}

int	sort_check_asc(t_LinkedDeque *deque)
{
	t_DequeNode	*temp;
	int			n;
	int			result;

	temp = deque->frontnode;
	n = temp->data;
	result = 0;
	while (temp->rlink)
	{
		if (temp->rlink->data > n)
		{
			result = 1;
			n = temp->rlink->data;
		}
		else
		{
			result = 0;
			break ;
		}
		temp = temp->rlink;
	}
	return (result);
}

static void	merge(int arr[], int start, int middle, int end)
{
	int	b[1000001];
	int	i;
	int	j;
	int	k;

	i = start;
	j = middle + 1;
	k = 0;
	while (i <= middle && j <= end)
	{
		if (arr[i] <= arr[j])
			b[k++] = arr[i++];
		else
			b[k++] = arr[j++];
	}
	while (i <= middle)
		b[k++] = arr[i++];
	while (j <= end)
		b[k++] = arr[j++];
	k--;
	while (k >= 0)
	{
		arr[start + k] = b[k];
		k--;
	}
}

void	merge_sort(int arr[], int start, int end)
{
	int	middle;

	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle + 1, end);
		merge(arr, start, middle, end);
	}
}

void	find_pivot(t_LinkedDeque *deque_a, t_greedy *greedy)
{
	t_DequeNode	*temp;
	int			start;
	int			*arr;
	int			len;

	temp = deque_a->frontnode;
	len = deque_size(deque_a);
	arr = (int *)malloc(sizeof(int) * len);
	start = 0;
	while (temp)
	{
		arr[start] = temp->data;
		start++;
		temp = temp->rlink;
	}
	merge_sort(arr, 0, len - 1);
	match_idx(deque_a, arr);
	greedy->max = arr[len - 1];
	greedy->min = arr[0];
	greedy->mid = arr[len / 2];
	free(arr);
}
