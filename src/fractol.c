/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:20:08 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:20:16 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_image		*mlx_win_init(void *mlx)
{
	t_image	*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		exit(0);
	image->image = mlx_new_image(mlx, WIDHT, HIGHT);
	image->data_addr = mlx_get_data_addr(image->image, \
&image->bpp, &image->sl, &image->endian);
	return (image);
}

void		ft_exit(t_fractol *data)
{
	free(data);
	data = NULL;
	exit(1);
}

void		choose_fract(t_fractol *data)
{
	set_fractol(data);
	data->win = mlx_new_window(data->mlx, WIDHT, HIGHT, "Fractol");
	data->img = mlx_win_init(data->mlx);
	pth_fun(data);
	mlx_hook(data->win, 4, 0, zoom, data);
	mlx_hook(data->win, 6, 0, mouse_jul, data);
	mlx_key_hook(data->win, keys, data);
	mlx_hook(data->win, 2, 0, loop_key, data);
	mlx_loop(data->mlx);
}

int			check_in(t_fractol *data, char **argv)
{
	if (strcmp(argv[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		data->fract = 2;
	else if (ft_strcmp(argv[1], "duobrot") == 0)
		data->fract = 3;
	else if (ft_strcmp(argv[1], "tribrot") == 0)
		data->fract = 4;
	else
	{
		ft_putendl("Usage: /fractol \"mandelbrot\", \"julia\", \
\"burning_ship\", \"duobrot\", \"tribrot\"");
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_fractol *data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		ft_exit(data);
	if (argc == 2)
	{
		data->mlx = mlx_init();
		if ((check_in(data, argv)) == -1)
			return (0);
		choose_fract(data);
	}
	else
	{
		ft_putendl("Usage: /fractol \"mandelbrot\", \"julia\", \
\"burning_ship\", \"duobrot\", \"tribrot\"");
		ft_exit(data);
	}
	return (0);
}
