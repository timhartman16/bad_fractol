/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:35:03 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:35:04 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *buf, int ch, size_t count)
{
	size_t			i;
	unsigned char	*buf1;

	i = 0;
	buf1 = (unsigned char *)buf;
	while (i < count)
	{
		buf1[i] = ch;
		i++;
	}
	return (buf1);
}
