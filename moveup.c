/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:17:07 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:38:01 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	fillimages(t_map *map)
{
	map->down = mlx_load_png("./pngs/down.png");
	map->down1 = mlx_load_png("./pngs/down1.png");
	map->down2 = mlx_load_png("./pngs/down2.png");
	map->up = mlx_load_png("./pngs/forward.png");
	map->up1 = mlx_load_png("./pngs/forward1.png");
	map->up2 = mlx_load_png("./pngs/forward2.png");
	map->left = mlx_load_png("./pngs/left.png");
	map->left1 = mlx_load_png("./pngs/left1.png");
	map->left2 = mlx_load_png("./pngs/left2.png");
	map->right = mlx_load_png("./pngs/right.png");
	map->right1 = mlx_load_png("./pngs/right1.png");
	map->right2 = mlx_load_png("./pngs/right2.png");
	map->defleft = mlx_load_png("./pngs/defenceleft.png");
	map->defright = mlx_load_png("./pngs/defenceright.png");
	map->defup = mlx_load_png("./pngs/defenceup.png");
	map->defdown = mlx_load_png("./pngs/defencedown.png");
	map->groundimg = mlx_load_png("./pngs/ground.png");
	map->wallimg = mlx_load_png("./pngs/wall.png");
	map->coinimg = mlx_load_png("./pngs/coin.png");
	map->exitimg = mlx_load_png("./pngs/exit1.png");
}

void	moveup(t_map *map)
{
	static int	i;

	mlx_delete_image(map->mlx, map->player);
	if (i >= 0 && i <= 8)
		map->player = mlx_texture_to_image(map->mlx, map->up1);
	if (i >= 8 && i <= 16)
		map->player = mlx_texture_to_image(map->mlx, map->up);
	if (i >= 16 && i <= 24)
		map->player = mlx_texture_to_image(map->mlx, map->up2);
	if (i >= 24 && i <= 32)
		map->player = mlx_texture_to_image(map->mlx, map->up);
	if (i == 32)
		i = 0;
	i++;
	map->py -= 4;
	map->defpos = 1;
	mlx_image_to_window(map->mlx, map->player, map->px, map->py);
	counter(map);
}

void	movedown(t_map *map)
{
	static int	i;

	mlx_delete_image(map->mlx, map->player);
	if (i >= 0 && i <= 8)
		map->player = mlx_texture_to_image(map->mlx, map->down1);
	if (i >= 8 && i <= 16)
		map->player = mlx_texture_to_image(map->mlx, map->down);
	if (i >= 16 && i <= 24)
		map->player = mlx_texture_to_image(map->mlx, map->down2);
	if (i >= 24 && i <= 32)
		map->player = mlx_texture_to_image(map->mlx, map->down);
	if (i == 32)
		i = 0;
	i++;
	map->py += 4;
	map->defpos = 2;
	mlx_image_to_window(map->mlx, map->player, map->px, map->py);
	counter(map);
}

void	moveright(t_map *map)
{
	static int	i;

	mlx_delete_image(map->mlx, map->player);
	if (i >= 0 && i <= 8)
		map->player = mlx_texture_to_image(map->mlx, map->right1);
	if (i >= 8 && i <= 16)
		map->player = mlx_texture_to_image(map->mlx, map->right);
	if (i >= 16 && i <= 24)
		map->player = mlx_texture_to_image(map->mlx, map->right2);
	if (i >= 24 && i <= 32)
		map->player = mlx_texture_to_image(map->mlx, map->right);
	if (i == 32)
		i = 0;
	i++;
	map->px += 4;
	map->defpos = 3;
	mlx_image_to_window(map->mlx, map->player, map->px, map->py);
	counter(map);
}

void	moveleft(t_map *map)
{
	static int	i;

	mlx_delete_image(map->mlx, map->player);
	if (i >= 0 && i <= 8)
		map->player = mlx_texture_to_image(map->mlx, map->left1);
	if (i >= 8 && i <= 16)
		map->player = mlx_texture_to_image(map->mlx, map->left);
	if (i >= 16 && i <= 24)
		map->player = mlx_texture_to_image(map->mlx, map->left2);
	if (i >= 24 && i <= 32)
		map->player = mlx_texture_to_image(map->mlx, map->left);
	if (i == 32)
		i = 0;
	i++;
	map->px -= 4;
	map->defpos = 4;
	mlx_image_to_window(map->mlx, map->player, map->px, map->py);
	counter(map);
}

void	defence(t_map *map)
{
	mlx_delete_image(map->mlx, map->player);
	if (map->defpos == 1)
		map->player = mlx_texture_to_image(map->mlx, map->defup);
	if (map->defpos == 2)
		map->player = mlx_texture_to_image(map->mlx, map->defdown);
	if (map->defpos == 3)
		map->player = mlx_texture_to_image(map->mlx, map->defright);
	if (map->defpos == 4)
		map->player = mlx_texture_to_image(map->mlx, map->defleft);
	mlx_image_to_window(map->mlx, map->player, map->px, map->py);
}
