/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:28:26 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 13:55:19 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <ctype.h>

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
	double	zoom;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	x1;
	double	y1;
	int		params;
	double	c_x;
	double	c_y;
}	t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void	ft_posledovat(t_complex *z);
double	ft_modul_comlex(t_complex *z);
void	ft_slozhenie(t_complex *z, t_complex *c);
int		ft_check_uslovie(t_fractol *fract, t_complex *z, t_complex *c);
int		ft_close(void);
int		key_press(int key, t_fractol *fract);
int		ft_mouse_zoom(int button, int x, int y, t_fractol *fract);
double	ft_atof(char *s);
void	ft_init_fractol(t_fractol *fract, int argc, char **argv);
int		ft_fractol_name_check(t_fractol *fract, char **argv);
void	ft_wrong_parameters(void);
void	ft_draw(t_fractol *fract);
void	put_pxl_to_img(t_fractol *fract, int x, int y, int color);
void	ft_put_pixels(t_fractol *fract);
void	ft_draw_mandelbrot(t_fractol *fract);
void	ft_draw_julia(t_fractol *fract);

#endif