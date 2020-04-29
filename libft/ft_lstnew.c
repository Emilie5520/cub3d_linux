/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:57:25 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/22 16:46:41 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nouvelelement;

	nouvelelement = malloc(sizeof(t_list));
	if (nouvelelement == NULL)
		return (NULL);
	nouvelelement->content = content;
	nouvelelement->next = NULL;
	return (nouvelelement);
}
