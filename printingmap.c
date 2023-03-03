/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printingmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:26:59 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:44:11 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	printbackground(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	map->wall = mlx_texture_to_image(map->mlx, map->wallimg);
	map->ground = mlx_texture_to_image(map->mlx, map->groundimg);
	while (map->mapg[++i])
	{
		j = -1;
		x = 0;
		while (map->mapg[i][++j])
		{
			if (map->mapg[i][j] == '1')
				mlx_image_to_window(map->mlx, map->wall, x, y);
			if (map->mapg[i][j] == '0' || map->mapg[i][j] == 'P'
				|| map->mapg[i][j] == 'C' || map->mapg[i][j] == 'E')
				mlx_image_to_window(map->mlx, map->ground, x, y);
			x += 100;
		}
		y += 100;
	}
}

void	printexit(t_map *map)
{
	map->exit = mlx_texture_to_image(map->mlx, map->exitimg);
	mlx_image_to_window(map->mlx, map->exit, map->pos_e[1] * 100,
		map->pos_e[0] * 100);
}

void	printcoin(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	map->coin = mlx_texture_to_image(map->mlx, map->coinimg);
	while (map->mapg[i])
	{
		j = 0;
		x = 0;
		while (map->mapg[i][j])
		{
			if (map->mapg[i][j] == 'C')
				mlx_image_to_window(map->mlx, map->coin, x, y);
			j++;
			x += 100;
		}
		y += 100;
		i++;
	}
}
