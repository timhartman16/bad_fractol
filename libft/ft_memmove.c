/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:34:59 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:35:00 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	i = 0;
	if (!(dst) && !(src))
		return (0);
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	if (dst1 <= src1)
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			dst1[len] = src1[len];
		}
	}
	return (dst1);
}
