/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:20:35 by madan             #+#    #+#             */
/*   Updated: 2020/11/07 18:08:18 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define HIGHT 700
# define WIDHT 1000
# define THREADS 140
# define THREAD_W 5

# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bpp;
	int				sl;
	int				endian;
}					t_image;

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_fractol
{
	int				x;
	int				y;
	int				e;
	int				b;
	double			off_x;
	double			off_y;
	int				fract;
	t_color			color;
	void			*mlx;
	void			*win;
	t_image			*img;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		c;
	t_complex		k;
	int				color_shift;
	double			zoom;
	int				jul_m;
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
int					mouse_jul(int x, int y, t_fractol *data);
int					zoom(int code, int x, int y, t_fractol *fratol);
int					keys(int code, t_fractol *data);
int					keys2(int code, t_fractol *data);
int					loop_key(int code, t_fractol *data);
void				ft_exit(t_fractol *data);

#endif
