/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:11:33 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 19:05:21 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	canmoveup(t_map *map)
{
	if (map->mapg[(map->py + 20) / 100][(map->px + 9) / 100] != '1'
		&& map->mapg[(map->py +20) / 100][(map->px + 91) / 100] != '1')
		return (1);
	return (0);
}

int	canmovedown(t_map *map)
{
	if (map->mapg[(map->py + 100) / 100][(map->px + 9) / 100] != '1'
		&& map->mapg[(map->py + 100) / 100][(map->px + 91) / 100] != '1')
		return (1);
	return (0);
}

int	canmoveright(t_map *map)
{
	if (map->mapg[(map->py + 29) / 100][(map->px + 96) / 100] != '1'
		&& map->mapg[(map->py + 71) / 100][(map->px + 96) / 100] != '1')
		return (1);
	return (0);
}

int	canmoveleft(t_map *map)
{
	if (map->mapg[(map->py + 29) / 100][(map->px + 4) / 100] != '1'
		&& map->mapg[(map->py + 71) / 100][(map->px + 4) / 100] != '1')
		return (1);
	return (0);
}
