/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:21:14 by madan             #+#    #+#             */
/*   Updated: 2020/10/31 17:21:22 by madan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	initial_complex(double re, double im) // берет комплексные числа (создает)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
