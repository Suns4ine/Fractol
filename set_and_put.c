/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:23:59 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:24:06 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(double iteration, t_fractol *fractol)
{
	t_color color;

	if ((int)iteration / fractol->max_iteration == 1)
		return (0);
	color.red = cos(fractol->color_shift % 3\
	+ 3.0 + 0.2 * iteration) * 127 + 128;
	color.green = cos(fractol->color_shift % 3\
	+ 2.0 + 0.2 * iteration) * 127 + 128;
	color.blue = cos(fractol->color_shift % 3\
	+ 1.0 + 0.2 * iteration) * 127 + 128;
	return ((unsigned int)color.red << 16 |
			(unsigned int)color.blue << 8 |
			(unsigned int)color.green);
}

void			put_pxl_to_img(t_fractol *fractol,\
int x, int y, unsigned int color)
{
	int i;

	i = (x * fractol->img->bpp >> 3) + (y * fractol->img->sl);
	fractol->img->data_addr[i] = color;
	fractol->img->data_addr[i++] = color >> 8;
	fractol->img->data_addr[i++] = color >> 16;
}

void			set_fractol(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->off_x = -2.4;
	fractol->off_y = -1.8;
	fractol->min = initial_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HIGHT / WIDHT;
	fractol->k = initial_complex(-0.4, 0.6);
	fractol->color_shift = 0;
	fractol->jul_m = 0;
	fractol->zoom = 200;
}
