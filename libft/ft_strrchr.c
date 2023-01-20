/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:02:38 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 12:57:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	while (idx > -1)
	{
		if (*(s + idx) == (char) c)
			return ((char *)(s + idx));
		idx--;
	}
	return (0);
}
