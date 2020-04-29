/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:02:47 by edouvier          #+#    #+#             */
/*   Updated: 2020/02/24 16:18:55 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parsing_read(t_env *e)
{
	if (ft_check_identifiants(e) == 0)
	{
		ft_putstr("Error\nmap");
		ft_exit(e);
	}
	ft_recup_map_2(e);
	ft_pos_perso(e);
	ft_orientation_perso(e);
}

void	ft_space(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
}

void	ft_mv_up(t_env *e)
{
	if (e->mvt.up == 1)
	{
		if ((e->map.tab_map[(int)(e->map.pos_n_y)]
				[(int)(e->map.pos_n_x + e->orientation.dir_x * 0.10)] != '1')
		&& (e->map.tab_map[(int)(e->map.pos_n_y)]
				[(int)(e->map.pos_n_x + e->orientation.dir_x * 0.10)] != '2'))
			e->map.pos_n_x += e->orientation.dir_x * 0.10;
		if ((e->map.tab_map[(int)(e->map.pos_n_y + e->orientation.dir_y * 0.10)]
				[(int)(e->map.pos_n_x)] != '1')
		&& (e->map.tab_map[(int)(e->map.pos_n_y + e->orientation.dir_y * 0.10)]
				[(int)(e->map.pos_n_x)] != '2'))
			e->map.pos_n_y += e->orientation.dir_y * 0.10;
	}
}

int		ft_deplacement(t_env *e)
{
	double tmp;

	tmp = e->map.pos_n_x + e->map.pos_n_y + e->map.plan_x + e->map.plan_y;
	e->mvt.vit_rot = 0.020;
	ft_mv_up(e);
	ft_deplacement_down(e);
	ft_deplacement_left(e);
	ft_deplacement_right(e);
	if (tmp != e->map.pos_n_x + e->map.pos_n_y + e->map.plan_x + e->map.plan_y)
		ft_init_image(e);
	return (0);
}

int		ft_exit_before(t_env *e)
{
	if (e->sprite)
		free(e->sprite);
	if (e->map.buff)
		free(e->map.buff);
	exit(0);
	return (0);
}
