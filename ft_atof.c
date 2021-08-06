/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:28:21 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 13:55:50 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	ft_check_sign(char **s, char sign)
{
	if (**s == '-')
	{
		sign = 1;
		(*s)++;
	}
	else
	{
		sign = 0;
		if (**s == '+')
			(*s)++;
	}
	return (sign);
}

double	ft_count_floor(char **s, double value)
{
	while (ft_isdigit(**s))
	{
		value = 10.0 * value + (**s - '0');
		(*s)++;
	}
	return (value);
}

double	ft_count_fraction(char **s, double value, double fraction)
{
	while (ft_isdigit(**s))
	{
		value += (**s - '0') * fraction;
		fraction *= 0.1;
		(*s)++;
	}
	return (value);
}

double	ft_atof(char *s)
{
	double	value;
	double	fraction;
	char	sign;

	value = 0.0;
	fraction = 0.1;
	sign = ft_check_sign(&s, sign);
	value = ft_count_floor(&s, value);
	if (*s == '.')
	{
		s++;
		value = ft_count_fraction(&s, value, fraction);
	}
	if (sign)
		value *= -1.0;
	return (value);
}
