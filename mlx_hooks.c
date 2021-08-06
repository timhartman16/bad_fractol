/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:27:55 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:27:58 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

int	key_press(int key, t_fractol *fract)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		fract->x1 -= 20 / fract->zoom;
	if (key == 124)
		fract->x1 += 20 / fract->zoom;
	if (key == 125)
		fract->y1 += 20 / fract->zoom;
	if (key == 126)
		fract->y1 -= 20 / fract->zoom;
	ft_draw(fract);
	return (0);
}

int	ft_mouse_zoom(int button, int x, int y, t_fractol *fract)
{
	if (button == 4)
	{
		fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom * 1.2));
		fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom * 1.2));
		fract->zoom *= 1.2;
		fract->max_kol_it++;
	}
	if (button == 5)
	{
		fract->x1 = (x / fract->zoom + fract->x1) - (x / (fract->zoom / 1.2));
		fract->y1 = (y / fract->zoom + fract->y1) - (y / (fract->zoom / 1.2));
		fract->zoom /= 1.2;
		if (fract->max_kol_it > 19)
			fract->max_kol_it--;
	}
	ft_draw(fract);
	return (0);
}
