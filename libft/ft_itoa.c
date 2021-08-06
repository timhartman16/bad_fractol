/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:34:37 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:34:39 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

long	ft_isotr(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_numlen(int num)
{
	int	leng;

	leng = 0;
	if (num < 0)
		leng++;
	if (num == 0)
		leng = 1;
	else
	{
		while (num != 0)
		{
			leng++;
			num = num / 10;
		}
	}
	return (leng);
}

void	ft_rev(char *s)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

char	*ft_itoa(int n1)
{
	char		*s;
	int			i;
	long int	n;

	n = (long int)n1;
	i = 0;
	n = ft_isotr(n);
	s = malloc(sizeof(char) * (ft_numlen(n1) + 1));
	if (!(s))
		return (0);
	while (n > 0 || n1 == 0)
	{
		if (n1 == 0)
		{
			s[i++] = '0';
			break ;
		}
		s[i++] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
	}
	if (n1 < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_rev(s);
	return (s);
}
