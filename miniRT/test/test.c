/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/06/01 21:14:01 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_hi
{
	int	arr[3];
	int	x;
}	t_hi;

t_hi	make_hi(int n)
{
	t_hi	hi;

	for (int i = 0; i < 3; i++)
		hi.arr[i] = i;
	hi.x = n;
	return (hi);
}

void	make_arr(t_hi *hi, int idx)
{
	hi[idx] = make_hi(idx);
}

int	main(void)
{
	t_hi	hi_arr[3];

	for (int i = 0; i < 3; i++)
		make_arr(hi_arr, i);
	for (int i = 0; i < 3; i++)
	{
		printf("hi_idx: %d\n", i);
		for (int j = 0; j < 3; j++)
			printf("%d ", hi_arr[i].arr[j]);
		printf("\n");
		printf("x: %d\n\n", hi_arr[i].x);
	}
}

// cc test.c ./include/vec_utils/vec_utils.c ./include/vec_utils2.c ./include/vec_utils3.c