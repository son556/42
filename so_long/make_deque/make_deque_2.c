/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:06:06 by chanson           #+#    #+#             */
/*   Updated: 2022/12/21 21:08:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	deque_back(t_deque *deque, int x, int y)
{
	t_node	*temp;

	temp = new_node(x, y);
	deque_add_back(deque, temp);
}
