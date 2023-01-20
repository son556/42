/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:30:50 by chanson           #+#    #+#             */
/*   Updated: 2022/11/28 10:26:56 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list ap)
{
	char	*str;
	int		cnt;

	str = ft_itoa(va_arg(ap, int));
	cnt = (int)ft_strlen(str);
	write(1, str, cnt);
	free(str);
	return (cnt);
}

static void	print_unsigned(unsigned long n)
{
	char			c;
	char			*num;

	num = "0123456789";
	if (n > 9)
		print_unsigned(n / 10);
	c = num[n % 10];
	write(1, &c, 1);
}

int	print_unsingend_int(va_list ap)
{
	unsigned int	n;
	int				cnt;

	n = va_arg(ap, unsigned int);
	print_unsigned(n);
	cnt = 0;
	if (n == 0)
		cnt++;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int	print_string(va_list ap)
{
	int		cnt;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	cnt = (int)ft_strlen(str);
	write(1, str, cnt);
	return (cnt);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
