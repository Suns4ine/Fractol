/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:28:09 by madan             #+#    #+#             */
/*   Updated: 2019/09/20 17:10:45 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *i;

	i = (unsigned char*)s;
	if (n == 0)
		return (NULL);
	while (n > 0 && *i != (unsigned char)c)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (NULL);
	return (i);
}
