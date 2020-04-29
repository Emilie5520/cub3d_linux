/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:01:53 by edouvier          #+#    #+#             */
/*   Updated: 2020/01/13 15:24:13 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointeur;
	int		len;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	len = nmemb * size;
	pointeur = malloc(len);
	if (pointeur == NULL)
		return (NULL);
	ft_bzero(pointeur, len);
	return (pointeur);
}
