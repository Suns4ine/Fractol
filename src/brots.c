/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:18:52 by madan             #+#    #+#             */
/*   Updated: 2020/11/07 19:49:46 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	duobrot(t_fractol *data)
{
	int			i;
	t_complex	z;
	t_complex	q;

	i = 0;
	data->c.re = (double)data->x / data->zoom + data->off_x;
	data->c.im = (double)data->y / data->zoom + data->off_y;
	z = initial_complex(data->c.re, data->c.im);
	while (z.re * z.re + z.im * z.im < (1 << 8) &&\
i++ < data->max_iteration)
	{
		q = initial_complex(z.re, z.im);
		z = initial_complex((z.re * z.re - (3.0 * z.im * z.im))\
			* z.re + data->c.re, ((3.0 * z.re * z.re) - z.im * z.im)\
			* z.im + data->c.im);
		if (z.re == q.re && z.im == q.im)
		{
			i = data->max_iteration;
			break ;
		}
	}
	if (i != data->max_iteration)
		return ((double)i - log2(log2(z.re * z.re + z.im * z.im)) + 6.0);
	return ((double)i);
}

double	tribrot(t_fractol *data)
{
	int			i;
	t_complex	z;
	t_complex	q;
	t_complex	sz;

	i = 0;
	data->c.re = (double)data->x / data->zoom + data->off_x;
	data->c.im = (double)data->y / data->zoom + data->off_y;
	z = initial_complex(data->c.re, data->c.im);
	sz = initial_complex(z.re * z.re, z.im * z.im);
	while (sz.re + sz.im < (1 << 8) && i++ < data->max_iteration)
	{
		q = initial_complex(z.re, z.im);
		z = initial_complex(sz.re * sz.re + sz.im * (sz.im - 6.0 * sz.re) + \
			data->c.re, (4.0 * z.re * z.im) * (sz.re - sz.im) + data->c.im);
		if (z.re == q.re && z.im == q.im)
		{
			i = data->max_iteration;
			break ;
		}
		sz = initial_complex(z.re * z.re, z.im * z.im);
	}
	if (i != data->max_iteration)
		return ((double)i - log2(log2(sz.re + sz.im)) + 6.0);
	return ((double)i);
}
