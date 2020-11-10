/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:24:52 by madan             #+#    #+#             */
/*   Updated: 2019/09/20 21:45:48 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*str1;
	const unsigned char		*str2;
	size_t					i;

	i = 0;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (n > i)
	{
		str1[i] = str2[i];
		if (str1[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
