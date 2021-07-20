#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_fractol
{
	int		x;
	int		y;
	int		name;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		win_size;
	int		color;
	int		kol_it;
	int		max_kol_it;
	double 	zoom;
	double	zoom_perem;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void	ft_posledovat(t_complex *z)
{
	double	temp;

	temp = z->x * z->x - z->y * z->y;
	z->y = 2.0 * z->x * z->y;
	z->x = temp;
	return ;
}

double	ft_modul_comlex(t_complex *z)
{
	return (z->x * z->x + z->y * z->y);
}

void	ft_slozhenie(t_complex *z, t_complex *c)
{
	z->x += c->x;
	z->y += c->y;
	return ;
}

int	ft_check_uslovie(t_fractol *fract, t_complex *z, t_complex *c)
{
	while (fract->kol_it < fract->max_kol_it)
	{
		fract->kol_it++;
		ft_posledovat(z);
		ft_slozhenie(z, c);
		if (ft_modul_comlex(z) > 4.0)
			break ;
	}
	return (fract->kol_it);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s2[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_fractol_name_check(t_fractol *fract, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		fract->name = 0;
	else if (ft_strcmp(argv[1], "Julia") == 0)
		fract->name = 1;
	else
		return (0);
	return (1);
}

void	ft_init_fractol(t_fractol *fract)
{
	fract->win_size = 600;
	fract->color = 1;
	fract->kol_it = 0;
	fract->max_kol_it = 50;
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -2.0;
	fract->max_im = 2.0;
	fract->zoom = 1.0;
	fract->zoom_perem = (fract->max_re - fract->min_re) / fract->win_size;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, fract->win_size, fract->win_size, "fractol");
	fract->img = mlx_new_image(fract->mlx, fract->win_size, fract->win_size);
	fract->img_ptr = mlx_get_data_addr(fract->img, &fract->bits_per_pixel, &fract->size_line, &fract->endian);
}

void	put_pxl_to_img(t_fractol *fract, int x, int y, int color)
{
	if (fract->x < fract->win_size && fract->y < fract->win_size)
	{
		color = mlx_get_color_value(fract->mlx, color);
		ft_memcpy(fract->img_ptr + 4 * fract->win_size * y + x * 4, &color, sizeof(int));
	}
}

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
			c.x = (fract->x * fract->zoom_perem) + fract->min_re;
			c.y = (fract->y * fract->zoom_perem) + fract->min_im;
			fract->kol_it = 0;
			z.x = 0.0;
			z.y = 0.0;
			fract->kol_it = ft_check_uslovie(fract, &z, &c);
			fract->y++;
			if (fract->kol_it < fract->max_kol_it)
				put_pxl_to_img(fract, fract->x, fract->y, fract->kol_it * 10);
			else
				put_pxl_to_img(fract, fract->x, fract->y, 0x000000);
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, -1, -1);
}

void	ft_draw_julia(t_fractol *fract)
{
	t_complex	c;
	t_complex	z;

	fract->x = -1;
	while (fract->x < fract->win_size)
	{
		fract->y = -1;
		while (fract->y < fract->win_size)
		{
			z.x = (fract->x * fract->zoom_perem) + fract->min_re;
			z.y = (fract->y * fract->zoom_perem) + fract->min_im;
			fract->kol_it = 0;
			c.x = 0;
			c.y = 1;
			fract->kol_it = ft_check_uslovie(fract, &z, &c);
			fract->y++;
			if (fract->kol_it < fract->max_kol_it)
				put_pxl_to_img(fract, fract->x, fract->y, fract->kol_it * 10);
			else
				put_pxl_to_img(fract, fract->x, fract->y, 0x000000);
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, -1, -1);
}

void ft_draw(t_fractol *fract)
{
	mlx_clear_window(fract->mlx, fract->win);
	if (fract->name == 0)
		ft_draw_mandelbrot(fract);
	if (fract->name == 1)
		ft_draw_julia(fract);
}	

int	ft_close(void)
{
	exit(0);
	return (0);
}

int	key_press(int key, t_fractol *fract)
{
	t_complex d;

	d.x = fract->max_re - fract->min_re;
	d.y = fract->max_im - fract->min_im;
	if (key == 53)
		exit(0);
	if (key == 123)	//left
	{
		fract->min_re -= d.x * 0.05;
		fract->max_re -= d.x * 0.05;
	}
	if (key == 124)	//right
	{
		fract->min_re += d.x * 0.05;
		fract->max_re += d.x * 0.05;
	}
	if (key == 125)	//down
	{
		fract->min_im += d.y * 0.05;
		fract->max_im += d.y * 0.05;
	}
	if (key == 126)	//up
	{
		fract->min_im -= d.y * 0.05;
		fract->max_im -= d.y * 0.05;
	}
	ft_draw(fract);
	return (0);
}

int ft_mouse_zoom(int button, int x, int y, t_fractol *fract)
{
	if (button == 4)
	{
		fract->zoom = 0.8;
		fract->min_re = fract->min_re * fract->zoom;
		fract->min_im = fract->min_im * fract->zoom;
		fract->max_re = fract->max_re * fract->zoom;
		fract->max_im = fract->max_im * fract->zoom;
		fract->zoom_perem = (fract->max_re - fract->min_re) / fract->win_size;
		fract->max_kol_it++;
	}
	if (button == 5)
	{
		fract->zoom = 1.2;
		fract->min_re = fract->min_re * fract->zoom;
		fract->min_im = fract->min_im * fract->zoom;
		fract->max_re = fract->max_re * fract->zoom;
		fract->max_im = fract->max_im * fract->zoom;
		fract->zoom_perem = (fract->max_re - fract->min_re) / fract->win_size;
		if (fract->max_kol_it > 19)
			fract->max_kol_it--;
	}
	ft_draw(fract);
	return (0);
}

int main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc == 2)
	{
		if (ft_fractol_name_check(&fract, argv) == 0)
		{
			ft_putstr_fd("Wrong name", 1);
			return (0);
		}
		ft_init_fractol(&fract);
		ft_draw(&fract);
		mlx_hook(fract.win, 2, 0, key_press, &fract);
		mlx_hook(fract.win, 4, 0, ft_mouse_zoom, &fract);
		mlx_hook(fract.win, 17, 0, ft_close, &fract);
		mlx_loop(fract.mlx);
	}
	else
		ft_putstr_fd("Wrong number of parameters", 2);
	return (0);
}