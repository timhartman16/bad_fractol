/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:36:15 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:36:16 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_iscmp(char sym, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sym)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_find_lkrai(char const *str, char *set1, size_t k)
{
	while (str[k])
	{
		if (ft_iscmp(str[k], set1) == 1)
			k++;
		else
			break ;
	}
	return (k);
}

size_t	ft_find_rkrai(char const *str, char *set1, size_t k)
{
	while (str[k])
	{
		if (k == 0)
			return (k);
		if (ft_iscmp(str[k], set1) == 1)
			k--;
		else
			break ;
	}
	return (k);
}

char	*ft_mall(size_t len, size_t i, const char *s1)
{
	char	*ss1;

	if (len < i || ft_strlen(s1) == 0)
		ss1 = malloc(sizeof(char) * 1);
	else
		ss1 = malloc(sizeof(char) * (len - i + 2));
	if (!(ss1))
		return (0);
	return (ss1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ss1;
	char	*set1;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	if (!(s1) || !(set))
		return (0);
	set1 = (char *)set;
	if (ft_strlen(s1) != 0)
		len = ft_strlen(s1) - 1;
	else
		len = 0;
	i = ft_find_lkrai(s1, set1, 0);
	len = ft_find_rkrai(s1, set1, len);
	ss1 = ft_mall(len, i, s1);
	if (!(ss1))
		return (0);
	while (i <= len)
		ss1[j++] = s1[i++];
	ss1[j] = '\0';
	return (ss1);
}
