/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:28:57 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 10:14:35 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*src1;

	i = 0;
	src1 = (char*)src;
	if (size == 0)
		return (ft_strlen(src1));
	while (dest[i] != '\0' && i < size)
		i++;
	j = i;
	while (src1[i - j] != '\0' && i < size - 1)
	{
		dest[i] = src1[i - j];
		i++;
	}
	if (j < size)
		dest[i] = '\0';
	return (ft_strlen(src1) + j);
}
