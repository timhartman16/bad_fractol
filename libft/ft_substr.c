/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:36:18 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:36:19 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*dest_s;

	if (!(s))
		return (0);
	i = 0;
	len_s = ft_strlen(s);
	if (start + len > len_s)
		len = len_s - start;
	if (start >= len_s)
		len = 0;
	dest_s = malloc(sizeof(char) * (len + 1));
	if (!(dest_s))
		return (0);
	while (s[start] && len > 0)
	{
		dest_s[i] = s[start];
		i++;
		len--;
		start++;
	}
	dest_s[i] = '\0';
	return (dest_s);
}
