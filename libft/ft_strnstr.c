/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:26:06 by madan             #+#    #+#             */
/*   Updated: 2019/09/15 18:15:52 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		if (i + k > len)
			return (NULL);
		if (ft_strncmp(s1, s2, k) == 0)
			return ((char*)s1);
		i++;
		s1++;
	}
	return (NULL);
}
