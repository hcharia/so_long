/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:36:23 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:36:56 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	freemap(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapg[i])
	{
		free (map->mapg[i]);
		i++;
	}
	free(map->mapg);
	i = 0;
	while (map->cpymapg[i])
	{
		free (map->cpymapg[i]);
		i++;
	}
	free(map->cpymapg);
	free (map->v);
}
