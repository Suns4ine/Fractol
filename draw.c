/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:19:19 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:19:29 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

double	fractals(t_fractol *data)
{
	if (data->fract == 0)
		return (mandelbrot(data));
	else if (data->fract == 1)
		return (julia(data));
	else if (data->fract == 2)
		return (burning_ship(data));
	else if (data->fract == 3)
		return (duobrot(data));
	else if (data->fract == 4)
		return (tribrot(data));
	return (0);
}

void	draw(void *frag)
{
	t_fractol	*fractol;
	double		i;

	fractol = (t_fractol *)frag;
	fractol->y = fractol->b;
	while (fractol->y < fractol->e)
	{
		fractol->x = 0;
		while (fractol->x < WIDHT)
		{
			i = fractals(fractol);
			put_pxl_to_img(fractol, fractol->x, fractol->y, \
get_color(i, fractol));
			fractol->x++;
		}
		fractol->y++;
	}
}

void	pth_fun(t_fractol *data)
{
	pthread_t	tr[THREADS]; //многопоточность ??расшарить
	t_fractol	fract[THREADS]; // наша структура
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void *)&fract[i], (void *)data, sizeof(t_fractol));
		fract[i].b = i * THREAD_W; //условное начало границы нашего потока
		fract[i].e = (i + 1) * THREAD_W; // условный конец нашего потока
		pthread_create(&tr[i], NULL, (void *)draw, (void*)&fract[i]); //создает потоки
		i++;
	}
	while (i--)
		pthread_join(tr[i], NULL); //завершает потоки
	mlx_put_image_to_window(data->mlx, data->win, data->img->image, 0, 0); //вставляет картинку в наше окно
}
