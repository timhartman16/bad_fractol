/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:28:38 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:28:40 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
