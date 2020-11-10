/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:01:06 by madan             #+#    #+#             */
/*   Updated: 2019/09/15 21:31:21 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					l;
	unsigned long long	k;

	i = 0;
	l = 1;
	k = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		l = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	if (k > 9223372036854775807)
	{
		if (l == -1)
			return (0);
		return (-1);
	}
	return (k * l);
}
