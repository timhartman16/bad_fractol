#include "fractol.h"

void	ft_draw_mandelbrot(t_fractol *fract)
{
	t_complex	c;
	t_complex	z;

	fract->x = -1;
	while (fract->x < fract->win_size)
	{
		fract->y = -1;
		while (fract->y < fract->win_size)
		{
			c.x = fract->x / fract->zoom + fract->x1;
			c.y = fract->y / fract->zoom + fract->y1;
			fract->kol_it = 0;
			z.x = 0.0;
			z.y = 0.0;
			fract->kol_it = ft_check_uslovie(fract, &z, &c);
			fract->y++;
			ft_put_pixels(fract);
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, -1, -1);
}
