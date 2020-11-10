/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:24:21 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:24:29 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	zoom(int code, int x, int y, t_fractol *fractol)
{
	if (code == 5)
	{
		fractol->off_x = (x / fractol->zoom + fractol->off_x) -
			(x / (fractol->zoom / 1.2));
		fractol->off_y = (y / fractol->zoom + fractol->off_y) -
			(y / (fractol->zoom / 1.2));
		fractol->zoom /= 1.2;
	}
	else
	{
		fractol->off_x = (x / fractol->zoom + fractol->off_x) -
			(x / (fractol->zoom * 1.2));
		fractol->off_y = (y / fractol->zoom + fractol->off_y) -
			(y / (fractol->zoom * 1.2));
		fractol->zoom *= 1.2;
	}
	pth_fun(fractol);
	return (0);
}
