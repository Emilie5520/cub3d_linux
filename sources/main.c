/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:21 by edouvier          #+#    #+#             */
/*   Updated: 2020/04/11 09:51:43 by edouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_image(t_env *e)
{
	if (!(e->mlx.new_image = mlx_new_image(e->mlx.ptr,
					e->axes.axe_x, e->axes.axe_y)))
	{
		ft_putstr("Error\nmlx_new_image");
		ft_exit(e);
	}
	if (!(e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
			&e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian)))
	{
		ft_putstr("Error\nmlx_get_data_addr");
		ft_exit(e);
	}
	if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
	{
		ft_putstr("Error\nMalloc e->spt.dist_wall");
		ft_exit(e);
	}
	ft_raycasting(e);
	ft_sprite(e);
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win_ptr,
			e->mlx.new_image, 0, 0);
	mlx_do_sync(e->mlx.ptr);
	mlx_destroy_image(e->mlx.ptr, e->mlx.new_image);
}

void	ft_open_window(t_env *e)
{
	if (!(e->mlx.ptr = mlx_init()))
	{
		ft_putstr("Error\nmlx_init");
		ft_exit(e);
	}
	ft_check_resolution_next(e);
	if (!(e->mlx.win_ptr = mlx_new_window(e->mlx.ptr, e->axes.axe_x,
			e->axes.axe_y, "Cub3d")))
	{
		ft_putstr("Error\nmlx_new_window");
		ft_exit(e);
	}
	ft_textures(e);
	ft_init_sprite(e);
	ft_init_image(e);
	ft_check_wall(e);
	ft_check_space(e);
	mlx_do_key_autorepeatoff(e->mlx.ptr);
	mlx_hook(e->mlx.win_ptr, 2, 1, &ft_key_down, e);
	mlx_hook(e->mlx.win_ptr, 3, 2, &ft_key_up, e);
	mlx_hook(e->mlx.win_ptr, 33, 0, &ft_exit, e);
	mlx_loop_hook(e->mlx.ptr, &ft_deplacement, e);
	mlx_loop(e->mlx.ptr);
}

int		ft_exit(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->map.nbr_sprite)
	{
		if (e->sprite[i].image.get_data)
			mlx_destroy_image(e->mlx.ptr, e->sprite[i].image.win_ptr);
		if (e->sprite[i].image.win_ptr == NULL)
		{
			ft_putstr(" error");
			return (-1);
		}
		if (e->mlx.ptr && e->mlx.win_ptr)
			mlx_clear_window(e->mlx.ptr, e->mlx.win_ptr);
		i++;
	}
	if (e->sprite)
		free(e->sprite);
	if (e->map.buff)
		free(e->map.buff);
	exit(0);
	return (0);
}

void	ft_push_bmp(t_env *e)
{
	e->mlx.ptr = mlx_init();
	if (!(e->sprite = (t_sprite*)ft_calloc(sizeof(t_sprite),
					e->map.nbr_sprite)))
	{
		ft_putstr("Error\nMalloc sprite");
		ft_exit(e);
	}
	ft_textures(e);
	ft_init_sprite(e);

	e->mlx.new_image = mlx_new_image(e->mlx.ptr, e->axes.axe_x, e->axes.axe_y);
	e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
			&e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian);
	if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
	{
		ft_putstr("Error\nMalloc e->spt.dist_wall");
		ft_exit(e);
	}
	ft_raycasting(e);
	ft_sprite(e);
	ft_bmp(e);
	ft_exit_before(e);
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		len;

	ft_bzero(&e, sizeof(t_env));
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\nNumbers of argc incorrect");
		ft_exit(&e);
	}
	len = (ft_strlen(argv[1]) - 4);
	ft_read_map(argv, &e);
	if (argv[2] && !ft_strncmp(argv[2], "--save", 6))
		ft_push_bmp(&e);
	if (!argv[1] || (ft_strncmp(argv[1] + len, ".cub", 4)))
	{
		ft_putstr("Error\nNo map or no file .cub");
		ft_exit(&e);
	}
	if (!(e.sprite = (t_sprite*)ft_calloc(sizeof(t_sprite), e.map.nbr_sprite)))
	{
		ft_putstr("Error\nMalloc sprite");
		ft_exit(&e);
	}
	ft_open_window(&e);
	return (0);
}
