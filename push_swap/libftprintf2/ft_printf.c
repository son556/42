/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:39:56 by chanson           #+#    #+#             */
/*   Updated: 2022/11/28 12:33:12 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hexa(unsigned long n, int def)
{
	char			c;
	char			*num;

	num = "0123456789";
	if (n > 15)
		print_hexa(n / 16, def);
	if (n % 16 > 9 && def)
		c = 'a' + (n % 16 - 10);
	else if (n % 16 < 10 && def)
		c = num[n % 16];
	else if (n % 16 > 9 && !def)
		c = 'A' + (n % 16 - 10);
	else if (n % 16 < 10 && !def)
		c = num[n % 16];
	write(1, &c, 1);
}

static int	print_pointer(va_list ap)
{
	unsigned long	un;
	int				cnt;

	un = va_arg(ap, unsigned long);
	write(1, "0x", 2);
	cnt = 2;
	print_hexa(un, 1);
	if (un == 0)
		cnt++;
	while (un)
	{
		un /= 16;
		cnt++;
	}
	return (cnt);
}

int	def_hexa(va_list ap, char c)
{
	unsigned int	n;
	int				cnt;

	n = va_arg(ap, unsigned int);
	cnt = 0;
	if (c == 'x')
		print_hexa(n, 1);
	else if (c == 'X')
		print_hexa(n, 0);
	if (n == 0)
		cnt++;
	while (n)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

static int	define_variable(char c, va_list ap)
{
	int		n;
	char	ch;

	n = 0;
	if (c == 'd' || c == 'i')
		n = print_int(ap);
	else if (c == 'c')
	{
		ch = va_arg(ap, int);
		n = 1;
		write(1, &ch, 1);
	}
	else if (c == 's')
		n = print_string(ap);
	else if (c == 'p')
		n = print_pointer(ap);
	else if (c == 'x' || c == 'X')
		n = def_hexa(ap, c);
	else if (c == 'u')
		n = print_unsingend_int(ap);
	else if (c == '%')
		n = print_percent();
	return (n);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	char	*temp;
	int		i;
	int		cnt;

	temp = ft_strdup(input);
	va_start(ap, input);
	i = 0;
	cnt = 0;
	while (temp[i])
	{
		if (temp[i] == '%')
		{
			cnt += define_variable(temp[i + 1], ap);
			i += 2;
			cnt -= 2;
		}
		else
			write(1, &temp[i++], 1);
	}
	cnt += i;
	free(temp);
	return (cnt);
}
