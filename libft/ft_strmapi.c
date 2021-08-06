/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:35:58 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:35:59 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	size_t	len;
	size_t	i;

	i = 0;
	if (!(s))
		return (0);
	len = ft_strlen(s);
	ss = malloc(sizeof(char) * (len + 1));
	if (!(ss))
		return (0);
	while (i < len)
	{
		ss[i] = (f)(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
