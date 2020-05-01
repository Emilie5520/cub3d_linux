/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <edouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:16:05 by edouvier          #+#    #+#             */
/*   Updated: 2020/04/30 17:16:15 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parsing_line_s(t_env *e, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == ' ' && e->identifiants.m == 0)
	{
		if (e->identifiants.s == 0)
		{
			e->root_textures.sprite = ft_recup_root(line, e, i);
			e->identifiants.s = 1;
		}
		else
		{
			ft_putstr("Error\nTwo S textures, only one");
			ft_exit(e);
		}
	}
	ft_parsing_line_f(e, line, i);
}

void	ft_parsing_line_f(t_env *e, char *line, int i)
{
	if (line[i] == 'F' && line[i + 1] == ' ' && e->identifiants.m == 0)
	{
		if (e->identifiants.f == 0)
		{
			e->colors.color_sol = ft_recup_color(line, e, i);
			e->identifiants.f = 1;
		}
		else
		{
			ft_putstr("Error\nTwo colors F, only one");
			ft_exit(e);
		}
	}
	ft_parsing_line_again(e, line, i);
}

void	ft_parsing_line_no(t_env *e, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& e->identifiants.m == 0)
	{
		if (e->identifiants.no == 0)
		{
			e->root_textures.north = ft_recup_root(line, e, i);
			e->identifiants.no = 1;
		}
		else
		{
			ft_putstr("Error\nTwo N0 textures, only one");
			ft_exit(e);
		}
	}
	ft_parsing_line_so(e, line, i);
}

void	ft_parsing_line_so(t_env *e, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& e->identifiants.m == 0)
	{
		if (e->identifiants.so == 0)
		{
			e->root_textures.south = ft_recup_root(line, e, i);
			e->identifiants.so = 1;
		}
		else
		{
			ft_putstr("Error\nTwo S0 textures, only one");
			ft_exit(e);
		}
	}
	ft_parsing_line_we(e, line, i);
}

void	ft_parsing_line_we(t_env *e, char *line, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '
	&& e->identifiants.m == 0)
	{
		if (e->identifiants.we == 0)
		{
			e->root_textures.west = ft_recup_root(line, e, i);
			e->identifiants.we = 1;
		}
		else
		{
			ft_putstr("Error\nTwo WE, only one");
			ft_exit(e);
		}
	}
	ft_parsing_line_next(e, line, i);
}
