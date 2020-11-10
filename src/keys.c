/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:21:49 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:21:57 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	keys(int code, t_fractol *data)
{
	if (code == 53)
		ft_exit(data);
	if (code == 49)
	{
		if (!data->jul_m)
			data->jul_m = 1;
		else
			data->jul_m = 0;
	}
	if (code == 47)
		data->color_shift += 1;
	return (keys2(code, data));
}

int	keys2(int code, t_fractol *data)
{
	if (code == 18)
		data->fract = 0;
	if (code == 19)
		data->fract = 1;
	if (code == 20)
		data->fract = 2;
	if (code == 21)
		data->fract = 3;
	if (code == 23)
		data->fract = 4;
	if (code == 29)
	{
		data->zoom = 200;
		data->off_x = -2.4;
		data->off_y = -1.8;
		data->max_iteration = 50;
	}
	pth_fun(data);
	return (0);
}

int	loop_key(int code, t_fractol *data)
{
	if (code == 33)
	{
		if (data->max_iteration < 50)
			data->max_iteration += 1;
		else
			data->max_iteration = (int)(data->max_iteration * 1.05);
	}
	if (code == 30)
	{
		if (data->max_iteration > 50)
			data->max_iteration = (int)(data->max_iteration * 0.95);
		if (data->max_iteration > 1)
			data->max_iteration -= 1;
	}
	if (code == 126)
		data->off_y += 10 / data->zoom;
	if (code == 125)
		data->off_y -= 10 / data->zoom;
	if (code == 124)
		data->off_x -= 10 / data->zoom;
	if (code == 123)
		data->off_x += 10 / data->zoom;
	pth_fun(data);
	return (0);
}

int	mouse_jul(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->jul_m == 1)
	{
		data->k = initial_complex(
			(double)x / (WIDHT / (data->max.re - data->min.re))
			+ data->min.re,
			(double)y / (HIGHT / (data->max.im - data->min.im))
			* -1 + data->max.im);
		pth_fun(data);
	}
	return (0);
}
