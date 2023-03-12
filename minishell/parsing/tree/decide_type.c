/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:29 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

int	decide_type(char *str)
{
	if (ft_strscmp(str, "<") == TRUE)
		return (TK_IRD);
	if (ft_strscmp(str, ">") == TRUE)
		return (TK_ORD);
	if (ft_strscmp(str, "<<") == TRUE)
		return (TK_HRD);
	if (ft_strscmp(str, ">>") == TRUE)
		return (TK_ARD);
	if (ft_strscmp(str, "|") == TRUE)
		return (TK_PIPE);
	if (ft_strscmp(str, "&&") == TRUE)
		return (TK_AND);
	if (ft_strscmp(str, "||") == TRUE)
		return (TK_OR);
	return (TK_STR);
}
