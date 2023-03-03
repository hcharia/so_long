/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coinpostion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:52:42 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:36:43 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	coinposition(t_map *map)
{
	if (map->mapg[(map->py + 50) / 100][(map->px + 50) / 100] == 'C')
	{
		map->mapg[(map->py + 50) / 100][(map->px + 50) / 100] = '0';
		mlx_image_to_window(map->mlx, map->ground, ((map->px + 50) / 100) * 100,
			((map->py + 50) / 100) * 100);
		map->numcoins--;
	}
}

int	howmanycoins(t_map *map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (map->mapg[i])
	{
		j = 0;
		while (map->mapg[i][j])
		{
			if (map->mapg[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

void	khroj(t_map *map)
{
	if (map->mapg[(map->py + 50) / 100][(map->px + 50) / 100] == 'E'
		&& map->numcoins == 0)
	{
		mlx_close_window(map->mlx);
	}
}

void	counter(t_map *map)
{
	static int	result;

	if ((map->py + map->px) % 100 == 0)
	{
		result++;
		ft_putnbr_fd(result, 1);
		ft_putchar_fd('\n', 1);
	}
}
