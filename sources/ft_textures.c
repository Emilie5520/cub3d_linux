/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:49:19 by edouvier          #+#    #+#             */
/*   Updated: 2020/02/25 15:26:43 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_textures		ft_info_texture(char *root_texture, t_env *e)
{
	t_textures	texture;

	ft_memset(&texture, 0, sizeof(t_textures));
	if (!(texture.win_ptr = mlx_xpm_file_to_image(e->mlx.ptr,
			root_texture, &texture.w, &texture.h)))
	{
		ft_putstr("Error\nWrong texture");
		ft_exit_before(e);
	}
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.win_ptr,
			&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
	{
		ft_putstr("Error\nWrong texture");
		ft_exit_before(e);
	}
	return (texture);
}

t_mlx			ft_info_sprite(char *root_texture, t_env *e)
{
	t_mlx	texture;

	if (!(texture.win_ptr = mlx_xpm_file_to_image(e->mlx.ptr, root_texture,
			&texture.w, &texture.h)))
	{
		ft_putstr("Error\nWrong sprite");
		ft_exit_before(e);
	}
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.win_ptr,
			&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
	{
		ft_putstr("Error\nWrong sprite");
		ft_exit_before(e);
	}
	return (texture);
}

void			ft_textures(t_env *e)
{
	int			i;
	char		*tmp;

	i = -1;
	e->texture_north = ft_info_texture(e->root_textures.north, e);
	e->texture_south = ft_info_texture(e->root_textures.south, e);
	e->texture_east = ft_info_texture(e->root_textures.east, e);
	e->texture_west = ft_info_texture(e->root_textures.west, e);
	while (++i < e->map.nbr_sprite)
	{
		tmp = e->root_textures.sprite;
		e->sprite[i].image = ft_info_sprite(tmp, e);
	}
}

t_textures		ft_texture_wall(t_env *e)
{
	if (e->raycasting.side == 0 && e->map.ray_dir_x > 0)
	{
		return (e->texture_north);
	}
	else if (e->raycasting.side == 0 && e->map.ray_dir_x < 0)
		return (e->texture_south);
	else if (e->raycasting.side == 1 && e->map.ray_dir_y > 0)
		return (e->texture_east);
	else
		return (e->texture_west);
}

void			ft_put_textures(t_env *e, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_textures	texture_wall;

	texture_wall = ft_texture_wall(e);
	if (e->raycasting.side == 0)
		wall_x = e->map.pos_n_y +
			e->raycasting.perp_wall_dist * e->map.ray_dir_y;
	else
		wall_x = e->map.pos_n_x +
			e->raycasting.perp_wall_dist * e->map.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)texture_wall.w;
	y = e->map.draw_start;
	while (y < e->map.draw_end)
	{
		tex_y = (y - e->axes.axe_y / 2 + e->map.hauteur_line / 2) *
			texture_wall.h / e->map.hauteur_line;
		e->mlx.get_data[x + y * (e->mlx.size_line / 4)] =
			texture_wall.get_data[tex_x + tex_y * texture_wall.w];
		y++;
	}
}
