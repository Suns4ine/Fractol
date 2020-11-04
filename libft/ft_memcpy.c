/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:04:40 by madan             #+#    #+#             */
/*   Updated: 2019/09/16 18:05:25 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*sstr;
	unsigned char		*dstr;

	i = 0;
	sstr = (unsigned char*)src;
	dstr = (unsigned char*)dst;
	if (dst == src || !n)
		return ((void*)(dst));
	while (i < n)
	{
		dstr[i] = sstr[i];
		i++;
	}
	return ((void*)(dst));
}
