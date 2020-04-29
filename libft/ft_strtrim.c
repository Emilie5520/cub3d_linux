/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:07:56 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/22 11:24:22 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_trim(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_charset(char const *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = ft_strlen_trim(s1) - 1;
	l = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ft_strlen_trim(s1));
	if (str == NULL)
		return (NULL);
	while (is_charset(set, s1[i]) && s1[i] != '\0')
		i++;
	while (is_charset(set, s1[j]) && j >= 0)
		j--;
	while (i <= j)
	{
		str[l] = s1[i];
		l++;
		i++;
	}
	str[l] = '\0';
	return (str);
}
