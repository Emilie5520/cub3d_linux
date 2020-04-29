/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:25 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 10:41:47 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*src1;

	i = 0;
	j = 0;
	src1 = (char*)src;
	if (dest == NULL && src1 == NULL)
		return (0);
	while (src1[j] != '\0')
		j++;
	while (i < n)
	{
		if ((i < n - 1) && (src1[i] != '\0'))
			dest[i] = src1[i];
		else
		{
			dest[i] = '\0';
			return (j);
		}
		i++;
	}
	return (j);
}
