/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:28:09 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:28:11 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_start_params(t_fractol *fract, t_complex *c)
{
	c->x = 0;
	c->y = 1;
	if (fract->params == 1)
	{
		c->x = fract->c_x;
		c->y = fract->c_y;
	}
}

void	ft_draw_julia(t_fractol *fract)
{
	t_complex	c;
	t_complex	z;

	fract->x = -1;
	ft_init_start_params(fract, &c);
	while (fract->x < fract->win_size)
	{
		fract->y = -1;
		while (fract->y < fract->win_size)
		{
			z.x = fract->x / fract->zoom + fract->x1;
			z.y = fract->y / fract->zoom + fract->y1;
			fract->kol_it = 0;
			fract->kol_it = ft_check_uslovie(fract, &z, &c);
			fract->y++;
			ft_put_pixels(fract);
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, -1, -1);
}
