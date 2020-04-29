/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:26:41 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 13:52:18 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *c, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*c1;

	i = 0;
	j = 0;
	str1 = (char*)str;
	c1 = (char*)c;
	if (c1[j] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str1[i + j] == c1[j] && i + j < n)
		{
			j++;
			if (c1[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
