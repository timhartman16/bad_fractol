/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:35:41 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:35:42 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_dlin(char const *ss)
{
	size_t	len;

	if (ss)
		len = ft_strlen(ss);
	else
		len = 0;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*itog;
	size_t	i;

	i = 0;
	if (!(s1) && !(s2))
		return (0);
	itog = malloc(sizeof(char) * (ft_dlin(s1) + ft_dlin(s2) + 1));
	if (!(itog))
		return (0);
	while (s1 && s1[i])
	{
		itog[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		itog[ft_dlin(s1) + i] = s2[i];
		i++;
	}
	itog[ft_dlin(s1) + i] = '\0';
	return (itog);
}
