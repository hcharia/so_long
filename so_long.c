/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:50 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:24:02 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_ber(t_map *s, char *v)
{
	if (checkarg(v))
		return (1);
	if (!s)
		return (1);
	fillstruct(s, v);
	if (ft_doublelen(s->mapg) > 13 || ft_strlen(s->mapg[0]) > 25)
		return (1);
	if (checkmap(s->v) || map2dcheck(s->mapg))
		return (1);
	backtrack(s->cpymapg, s->pos_p);
	if (check_mapcpy(s->cpymapg))
		return (1);
	return (0);
}

void	hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_SPACE))
		defence (map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_UP) && canmoveup(map))
		moveup(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN) && canmovedown(map))
		movedown(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT) && canmoveleft(map))
		moveleft(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT) && canmoveright(map))
		moveright(map);
	coinposition(map);
	khroj(map);
}

int	main(int c, char **v)
{
	t_map	map;

	if (c != 2)
		return (1);
	if (check_ber(&map, v[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (freemap(&map), 1);
	}
	map.mlx = mlx_init(map.width, map.hight, "so_long", false);
	if (!map.mlx)
		return (EXIT_FAILURE);
	fillimages(&map);
	printbackground(&map);
	printexit(&map);
	printcoin (&map);
	map.player = mlx_texture_to_image(map.mlx, map.down);
	mlx_image_to_window(map.mlx, map.player, map.px, map.py);
	mlx_loop_hook(map.mlx, &hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	freemap(&map);
	return (EXIT_SUCCESS);
}
