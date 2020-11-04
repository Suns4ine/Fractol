/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:47:42 by madan             #+#    #+#             */
/*   Updated: 2019/09/20 21:49:37 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ddst;
	unsigned char *ssrc;

	ddst = (unsigned char*)dst;
	ssrc = (unsigned char*)src;
	if (ssrc < ddst)
		while (len--)
			((unsigned char *)ddst)[len] = ((unsigned char*)ssrc)[len];
	else
		ft_memcpy(ddst, src, len);
	return ((void*)dst);
}
