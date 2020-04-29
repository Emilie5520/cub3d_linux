/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:54:07 by edouvier          #+#    #+#             */
/*   Updated: 2020/02/12 20:06:44 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strlen_like(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (i - j);
}

int		count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c)
				|| (str[i] != c && str[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

char	*strdup_like(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (strlen_like(src, c) + 1));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)s;
	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (res == NULL)
		return (NULL);
	while (i < count_words(str, c))
	{
		while (str[j] && str[j] == c)
			j++;
		res[i] = strdup_like(&str[j], c);
		while (str[j] && str[j] != c)
			j++;
		i++;
	}
	res[i] = 0;
	return (res);
}
