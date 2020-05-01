/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <edouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:16:29 by edouvier          #+#    #+#             */
/*   Updated: 2020/04/30 17:16:31 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_identifiants(t_env *e)
{
	if (e->identifiants.r != 1 || e->identifiants.no != 1 ||
			e->identifiants.so != 1 || e->identifiants.we != 1
			|| e->identifiants.ea != 1 || e->identifiants.s != 1
			|| e->identifiants.f != 1 || e->identifiants.c != 1
			|| e->identifiants.m != 1)
		return (0);
	else
		return (1);
}

char	*ft_delete_space_next(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	while (str[i++])
	{
		if (str[i] != ' ')
			j++;
	}
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (str[i++])
	{
		if (str[i] != ' ')
			tmp[k++] = str[i];
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

void	ft_check_malloc(t_env *e)
{
	if (!(e->sprite = (t_sprite*)ft_calloc(sizeof(t_sprite),
		e->map.nbr_sprite)))
	{
		ft_putstr("Error\nMalloc sprite");
		ft_exit(e);
	}
}

int		ft_key_up(int keycode, t_env *e)
{
	if (keycode == 122)
		e->mvt.up = 0;
	if (keycode == 115)
		e->mvt.down = 0;
	if (keycode == 100)
		e->mvt.right = 0;
	if (keycode == 113)
		e->mvt.left = 0;
	if (keycode == 65363)
		e->mvt.rot_right = 0;
	if (keycode == 65361)
		e->mvt.rot_left = 0;
	if (keycode == 65307)
		ft_exit(e);
	return (0);
}
