/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <edouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 08:51:17 by edouvier          #+#    #+#             */
/*   Updated: 2020/05/05 08:51:20 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_exit_free(t_env *e)
{
	int		i;

	i = 0;
	free(e->mlx.ptr);
	free(e->mlx.win_ptr);
	free(e->texture_west.win_ptr);
	free(e->texture_east.win_ptr);
	free(e->texture_south.win_ptr);
	free(e->texture_north.win_ptr);
	free(e->root_textures.east);
	free(e->root_textures.south);
	free(e->root_textures.west);
	free(e->root_textures.north);
	free(e->root_textures.sprite);
	if (e->map.tab_map)
	{
		while (i <= e->raycasting.y)
		{
			free(e->map.tab_map[i]);
			i++;
		}
	}
	free(e->map.tab_map);
}
