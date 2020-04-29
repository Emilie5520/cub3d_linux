/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:17:22 by edouvier          #+#    #+#             */
/*   Updated: 2019/10/22 17:21:13 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*start;
	t_list		*new;
	t_list		*last;

	start = NULL;
	last = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if (!(new = malloc(sizeof(t_list))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new->content = f(new->content);
		new->next = NULL;
		if (!start)
			start = new;
		else
			ft_lstadd_back(&start, new);
		last = new;
		lst = lst->next;
	}
	return (start);
}
