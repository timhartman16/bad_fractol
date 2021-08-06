/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:24:26 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/06 14:20:54 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractol_name_check(t_fractol *fract, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		fract->name = 0;
	else if ((ft_strcmp(argv[1], "Julia") == 0 && argc == 2)
		|| (ft_strcmp(argv[1], "Julia") == 0 && argc == 4))
		fract->name = 1;
	else
		return (0);
	return (1);
}

void	ft_init_fractol(t_fractol *fract, int argc, char **argv)
{
	fract->win_size = 600;
	fract->color = 1;
	fract->kol_it = 0;
	fract->max_kol_it = 50;
	fract->x1 = -2.0;
	fract->y1 = -2.0;
	fract->zoom = 300;
	fract->params = 0;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, fract->win_size,
			fract->win_size, "fractol");
	fract->img = mlx_new_image(fract->mlx, fract->win_size, fract->win_size);
	fract->img_ptr = mlx_get_data_addr(fract->img, &fract->bits_per_pixel,
			&fract->size_line, &fract->endian);
	if (argc == 4)
	{
		fract->params = 1;
		fract->c_x = ft_atof(argv[2]);
		fract->c_y = ft_atof(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc == 2 || argc == 4)
	{
		if (ft_fractol_name_check(&fract, argc, argv) == 0)
		{
			ft_wrong_parameters();
			return (0);
		}
		ft_init_fractol(&fract, argc, argv);
		if (fract.c_x > 1 || fract.c_x < -1
			|| fract.c_y > 1 || fract.c_y < -1)
		{
			ft_wrong_parameters();
			return (0);
		}
		ft_draw(&fract);
		mlx_hook(fract.win, 2, 0, key_press, &fract);
		mlx_hook(fract.win, 4, 0, ft_mouse_zoom, &fract);
		mlx_hook(fract.win, 17, 0, ft_close, &fract);
		mlx_loop(fract.mlx);
	}
	else
		ft_wrong_parameters();
	return (0);
}
