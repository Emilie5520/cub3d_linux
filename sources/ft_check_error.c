/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:08:51 by edouvier          #+#    #+#             */
/*   Updated: 2020/04/11 10:01:33 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_wall_next(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	j = e->raycasting.y - 1;
	while (e->map.tab_map[j][i])
	{
		if (e->map.tab_map[j][i] != '1' && e->map.tab_map[j][i] != 'X')
		{
			ft_putstr("Error map\nOnly 1 on the edges of your map");
			ft_exit(e);
		}
		i++;
	}
	ft_check_wall_again(e);
}

void	ft_check_wall(t_env *e)
{
	int	i;

	i = 0;
	while (e->map.tab_map[0][i])
	{
		if (e->map.tab_map[0][i] != '1' && e->map.tab_map[0][i] != 'X')
		{
			ft_putstr("Error map\nOnly 1 on the edges of your map");
			ft_exit(e);
		}
		i++;
	}
	i = 0;
	while (i < e->raycasting.y)
	{
		if (e->map.tab_map[i][0] != '1' && e->map.tab_map[i][0] != 'X')
		{
			ft_putstr("Error map\nOnly 1 on the edges of your map");
			ft_exit(e);
		}
		i++;
	}
	ft_check_wall_next(e);
}

void	ft_check_resolution_next(t_env *e)
{
	int		sizex;
	int		sizey;

	sizex = 0;
	sizey = 0;
	if (!(mlx_get_screen_size(e->mlx.ptr, &sizex, &sizey)))
	{
		ft_putstr("Error\n mlx_get_screen");
		ft_exit_before(e);
	}
	if (e->axes.axe_x > sizex)
		e->axes.axe_x = sizex;
	if (e->axes.axe_y > sizey)
		e->axes.axe_y = sizey;
	if (e->axes.axe_x <= 0 || e->axes.axe_y <= 0)
	{
		ft_putstr("Error\nResolution <= 0");
		ft_exit(e);
	}
}

void	ft_check_color_next(t_env *e, char *line, int i, int j)
{
	ft_space(line, &i);
	j += line[i] == ',' ? 1 : 0;
	i++;
	ft_space(line, &i);
	j += ft_isdigit(line[i]) ? 1 : 0;
	ft_space(line, &i);
	if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
		j--;
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	j -= line[i] != '\0' ? 1 : 0;
	if (j != 5)
	{
		ft_putstr("Error\nWrong color");
		ft_exit(e);
	}
}

void	ft_check_color(t_env *e, char *line, int i)
{
	int	j;

	j = ft_isdigit(line[i]) ? 1 : 0;
	if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
		j--;
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	j += line[i] == ',' ? 1 : 0;
	i++;
	ft_space(line, &i);
	j += ft_isdigit(line[i]) ? 1 : 0;
	ft_space(line, &i);
	if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
		j--;
	while (ft_isdigit(line[i]))
		i++;
	ft_check_color_next(e, line, i, j);
}
