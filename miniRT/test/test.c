/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/05/13 21:02:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	// srand((unsigned int) time(NULL));
	// for (int i = 0; i < 20; i++)
	// 	printf("%f\n", (rand() / (RAND_MAX + 1.0)));
	double a = rand() / (RAND_MAX);
	double b = rand() / (RAND_MAX + 1.0);
	printf("%f %f\n", a, b);

	// srand(time(NULL)); // 시드값을 현재 시간으로 설정
    double rand_num = (double)rand() / (double)RAND_MAX; // 0과 1 사이의 난수 생성
    printf("%lf\n", rand_num);
}

auto cos_theta = fmin(dot(-uv, n), 1.0);
vec3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
return r_out_perp + r_out_parallel;

// cc test.c ./include/vec_utils/vec_utils.c ./include/vec_utils2.c ./include/vec_utils3.c