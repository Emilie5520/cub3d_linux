/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:40:29 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 10:43:53 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*str;

	tmp = NULL;
	str = (char*)s;
	if (c == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == c)
			tmp = str;
		str++;
	}
	if (tmp)
		return (tmp);
	return (NULL);
}
