/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:26:17 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/21 13:12:11 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*add;

	if (alst && new)
	{
		add = *alst;
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (add->next != NULL)
				add = add->next;
			add->next = new;
		}
	}
}
