/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:58:23 by chanson           #+#    #+#             */
/*   Updated: 2022/11/28 12:54:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft2/libft.h"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int	print_int(va_list ap);
int	print_char(va_list ap);
int	print_string(va_list ap);
int	print_unsingend_int(va_list ap);
int	print_percent(void);
int	ft_printf(const char *input, ...);
#endif