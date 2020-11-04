/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:34:14 by madan             #+#    #+#             */
/*   Updated: 2019/09/15 22:26:38 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strssd(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

static void		ft_nbrssd(char *str, int n, int *i)
{
	unsigned int k;

	k = n;
	if (n < 0)
	{
		str[*i] = '-';
		*i = (*i) + 1;
		k = -n;
	}
	if (k > 9)
	{
		ft_nbrssd(str, k / 10, i);
		ft_nbrssd(str, k % 10, i);
	}
	if (k < 10)
	{
		str[*i] = k + '0';
		*i = (*i) + 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		*i;
	int		k;

	i = &k;
	k = 0;
	str = (char*)malloc(sizeof(char) * (ft_strssd(n) + 1));
	if (str)
	{
		ft_nbrssd(str, n, i);
		str[k] = '\0';
	}
	return (str);
}
