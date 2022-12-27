/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:53:54 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 15:39:59 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_site(int **arr, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->custom.cnt = 0;
	while (y < game->map.y_size)
	{
		x = -1;
		while (x++ < game->map.x_size - 1)
		{
			if (arr[y][x] == -3)
			{
				game->custom.x = x;
				game->custom.y = y;
			}
			else if (arr[y][x] == -4)
			{
				game->user.x = x;
				game->user.y = y;
			}
			if (arr[y][x] == -2)
				game->custom.cnt++;
		}
		y++;
	}
}

char	*ft_itoa(int n)
{
	int			i;
	int			x;
	char		*result;
	char		*str;

	str = "0123456789";
	x = n;
	i = 0;
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	while (x)
	{
		x /= 10;
		i++;
	}
	if (n >= 0)
	{
		result = (char *)malloc(sizeof(char) * i);
		i--;
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (i + 1));
		result[0] = '-';
		n *= -1;
	}
	x = 0;
	while (n)
	{
		x = n % 10;
		n /= 10;
		result[i] = '0' + x;
		i--;
	}
	return (result);
}
