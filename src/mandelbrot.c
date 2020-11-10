/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:23:25 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:23:33 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	mandelbrot(t_fractol *data)
{
	int			i;
	t_complex	z;
	t_complex	q;

	i = 0;
	data->c.re = (double)data->x / data->zoom + data->off_x;
	data->c.im = (double)data->y / data->zoom + data->off_y;
	z = initial_complex(data->c.re, data->c.im);
	while (z.re * z.re + z.im * z.im < (1 << 4) &&\
i < data->max_iteration)
	{
		q = initial_complex(z.re, z.im);
		z = initial_complex(z.re * z.re - z.im * z.im + data->c.re,
							2.0 * z.re * z.im + data->c.im);
		if (z.re == q.re && z.im == q.im)
		{
			i = data->max_iteration;
			break ;
		}
		i++;
	}
	if (i != data->max_iteration)
		return ((double)i - log2(log2(z.re * z.re + z.im * z.im)) + 4.0);
	return ((double)i);
}

double	julia(t_fractol *data)
{
	int			i;
	t_complex	z;
	t_complex	q;

	i = 0;
	data->c.re = (double)data->x / data->zoom + data->off_x;
	data->c.im = (double)data->y / data->zoom + data->off_y;
	z = initial_complex(data->c.re, data->c.im);
	while (z.re * z.re + z.im * z.im <= 4 &&\
i < data->max_iteration)
	{
		q = initial_complex(z.re, z.im);
		z = initial_complex(z.re * z.re - z.im * z.im +
							data->k.re, 2.0 * z.re * z.im + data->k.im);
		if (z.re == q.re && z.im == q.im)
		{
			i = data->max_iteration;
			break ;
		}
		i++;
	}
	if (i != data->max_iteration)
		return ((double)i - log2(log2(z.re * z.re + z.im * z.im)) + 4.0);
	return ((double)i);
}

double	burning_ship(t_fractol *data)
{
	int			i;
	t_complex	z;
	t_complex	q;

	i = 0;
	data->c.re = (double)data->x / data->zoom + data->off_x;
	data->c.im = (double)data->y / data->zoom + data->off_y;
	z = initial_complex(data->c.re, data->c.im);
	while (z.re * z.re + z.re * z.re < (1 << 8) &&\
i < data->max_iteration)
	{
		q = initial_complex(z.re, z.im);
		z = initial_complex(fabs(z.re * z.re - z.im * z.im + data->c.re),
							fabs(2.0 * z.re * z.im) + data->c.im);
		if (z.re == q.re && z.im == q.im)
		{
			i = data->max_iteration;
			break ;
		}
		i++;
	}
	if (i != data->max_iteration)
		return ((double)i - log2(log2(z.re * z.re + z.im * z.im)) + 4.0);
	return ((double)i);
}
