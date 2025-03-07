/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:48:32 by madan             #+#    #+#             */
/*   Updated: 2019/09/20 15:33:53 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int i)
{
	if (i == '\t' || i == '\f' || i == '\r' \
			|| i == '\n' || i == '\v' || i == ' ')
		return (1);
	return (0);
}
