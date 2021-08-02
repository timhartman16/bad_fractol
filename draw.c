#include "fractol.h"

void	ft_draw(t_fractol *fract)
{
	mlx_clear_window(fract->mlx, fract->win);
	if (fract->name == 0)
		ft_draw_mandelbrot(fract);
	if (fract->name == 1)
		ft_draw_julia(fract);
}

void	put_pxl_to_img(t_fractol *fract, int x, int y, int color)
{
	if (fract->x < fract->win_size && fract->y < fract->win_size)
	{
		color = mlx_get_color_value(fract->mlx, color);
		ft_memcpy(fract->img_ptr + 4 * fract->win_size
			* y + x * 4, &color, sizeof(int));
	}
}

void	ft_put_pixels(t_fractol *fract)
{
	if (fract->kol_it < fract->max_kol_it)
		put_pxl_to_img(fract, fract->x, fract->y,
			fract->kol_it * 100000000);
	else
		put_pxl_to_img(fract, fract->x, fract->y, 0x000000);
}
