/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:54:08 by edouvier          #+#    #+#             */
/*   Updated: 2020/02/25 16:04:12 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_recup_root(char *line, t_env *e)
{
	int		i;
	char	**tab;
	char	*line2;

	if (!(tab = ft_split(line, ' ')))
	{
		ft_putstr("Error\n");
		ft_exit(e);
	}
	if (!(line2 = ft_strdup(tab[1])))
	{
		ft_putstr("Error\n");
		ft_exit(e);
	}
	if (tab[2])
	{
		ft_putstr("Error\nWrong .cub");
		ft_exit(e);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab[i]);
	free(tab);
	return (line2);
}

int		ft_recup_color(char *line, t_env *e)
{
	int		i;
	int		color;

	i = 1;
	ft_space(line, &i);
	ft_check_color(e, line, i);
	while (line[i] == ' ')
		i++;
	color = ft_atoi(&line[i]) * 65536;
	while (ft_isdigit(line[i]))
		i++;
	color += ft_atoi(&line[++i]) * 256;
	while (ft_isdigit(line[i]))
		i++;
	color += ft_atoi(&line[++i]);
	ft_space(line, &i);
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	if (line[i])
	{
		ft_putstr("Error\nWrong .cub");
		ft_exit(e);
	}
	return (color);
}

void	ft_recup_axes(t_env *e, char *line)
{
	int		i;

	i = 1;
	while (ft_isprint(line[i]) == 0)
		i++;
	i++;
	e->axes.axe_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isprint(line[i]) == 0)
		i++;
	i++;
	e->axes.axe_y = ft_atoi(&line[i]);
	ft_space(line, &i);
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	if (line[i])
	{
		ft_putstr("Error\nWrong .cub");
		ft_exit(e);
	}
}

int		ft_key_down(int keycode, t_env *e)
{
	if (keycode == 122)
		e->mvt.up = 1;
	if (keycode == 115)
		e->mvt.down = 1;
	if (keycode == 100)
		e->mvt.right = 1;
	if (keycode == 113)
		e->mvt.left = 1;
	if (keycode == 65363)
		e->mvt.rot_right = 1;
	if (keycode == 65361)
		e->mvt.rot_left = 1;
	return (0);
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
