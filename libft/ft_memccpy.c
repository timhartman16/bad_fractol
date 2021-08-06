/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:34:42 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:34:45 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	sym;

	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	sym = (unsigned char)c;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == sym)
		{
			return (&dst1[i + 1]);
		}
		i++;
	}
	return (NULL);
}
