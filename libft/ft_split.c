/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanastac <tanastac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:35:22 by tanastac          #+#    #+#             */
/*   Updated: 2021/08/04 10:35:23 by tanastac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_kolvo_strok(char const *s, char c)
{
	int	kol_strok;

	kol_strok = 0;
	while (s)
	{
		if (*s == '\0')
			return (0);
		while (*s == c)
			s++;
		if (*s == '\0')
			return (kol_strok);
		s = ft_strchr(s, c);
		kol_strok++;
	}
	return (kol_strok);
}

char	*ft_novaya_stroka(char const *start, char const *end)
{
	char	*stroka;
	char	*temp;

	stroka = (char *)malloc((end - start) + 2);
	temp = stroka;
	while (start != end)
	{
		*stroka = *start;
		stroka++;
		start++;
	}
	*stroka = '\0';
	return (temp);
}

char	**ft_ochistka(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	**ft_wordsplit(size_t words, char c, char const *s, char **mas)
{
	char		**mas1;
	char const	*word;

	mas1 = mas;
	while (words--)
	{		
		while (*s && *s == c)
			s++;
		word = s;
		while (*s && *s != c)
			s++;
		*mas = ft_novaya_stroka(word, s);
		if (!mas)
			return (ft_ochistka(mas1));
		mas++;
	}
	*mas = 0;
	return (mas1);
}

char	**ft_split(char const *s, char c)
{
	char	**mas;

	if (!s)
		return (0);
	mas = (char **)malloc(sizeof(char *) * (ft_kolvo_strok(s, c) + 1));
	if (!mas)
		return (0);
	mas = ft_wordsplit(ft_kolvo_strok(s, c), c, s, mas);
	if (!mas)
		return (0);
	return (mas);
}
