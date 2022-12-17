/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:02:42 by chanson           #+#    #+#             */
/*   Updated: 2022/12/12 16:03:26 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_rrr(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	if (!push_rra(deque_a) || !push_rrb(deque_b))
		return (0);
	return (1);
}
