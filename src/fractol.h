/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:20:35 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:20:41 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define HIGHT 700
# define WIDHT 1000
# define THREADS 140
# define THREAD_W 5

# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_complex //структура для комплексных чисел
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image //для картинки чтобы потом подать в mlx
{
	void			*image;
	char			*data_addr;
	int				bpp;
	int				sl;
	int				endian;
}					t_image;

typedef struct		s_color //цвет
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_fractol
{
	int				x;//координаты
	int				y;//координаты
	int				e;//конец координаты y в потоке
	int				b;//начало координаты у в потоке
	double			off_x;//смещение по х
	double			off_y;//смещение по у
	int				fract;//наш фрактал!!!!!!!!!!!!!
	t_color			color;//цвет
	void			*mlx;//млх
	void			*win;//окно
	t_image			*img;//изображение
	int				max_iteration;//максимальные итерации
	t_complex		min;
	t_complex		max;
	t_complex		c;//консантнта для мандельброта
	t_complex		k;//константа для джилии
	int				color_shift;//
	double			zoom;//зум
	int				jul_m;
	int				help;
}					t_fractol;

t_complex			initial_complex(double re, double im);
void				draw(void *frag);
void				pth_fun(t_fractol *data);
t_image				*mlx_win_init(void *mlx);
void				choose_fract(t_fractol *data);
int					check_in(t_fractol *data, char **argv);
void				put_pxl_to_img(t_fractol *fractol, int x,\
	int y, unsigned int color);
void				set_fractol(t_fractol *fractol);
double				mandelbrot(t_fractol *data);
double				julia(t_fractol *data);
double				burning_ship(t_fractol *data);
double				tribrot(t_fractol *data);
double				duobrot(t_fractol *data);
unsigned int		get_color(double iteration, t_fractol *fractol);
double				fractals(t_fractol *data);
int					mouse(int code, int x, int y, t_fractol *data);
int					mouse_jul(int x, int y, t_fractol *data);
int					zoom(int code, int x, int y, t_fractol *fratol);
int					keys(int code, t_fractol *data);
int					keys2(int code, t_fractol *data);
int					loop_key(int code, t_fractol *data);
void				ft_exit(t_fractol *data);

#endif
