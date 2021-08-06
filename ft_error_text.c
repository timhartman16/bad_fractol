/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:28:16 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 12:50:14 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_wrong_parameters(void)
{
	ft_putstr_fd("Your input is not correct.\n", 2);
	ft_putstr_fd("There are only two fractals.\n", 2);
	ft_putstr_fd("1. Mandelbrot\n", 2);
	ft_putstr_fd("2. Julia\n\n", 2);
	ft_putstr_fd("In Julia fractal you can also \n", 2);
	ft_putstr_fd("enter the starting coordinates x, y from [-1, 1]\n", 2);
	ft_putstr_fd("(by default they are x = 0, y = 1).\n", 2);
	ft_putstr_fd("You should enter like this:\n", 2);
	ft_putstr_fd("\t./fractol *name* *param1* *param2*\n", 2);
}
