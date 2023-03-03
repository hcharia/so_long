/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:46 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:42:12 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "/Users/hcharia/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_lst{
	char			*v;
	char			**mapg;
	char			**cpymapg;
	int				*pos_p;
	int				px;
	int				py;
	int				*pos_e;
	int				width;
	int				hight;
	int				defpos;
	int				numcoins;
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*wall;
	mlx_image_t		*ground;
	mlx_image_t		*coin;
	mlx_image_t		*enemy;
	mlx_texture_t	*down;
	mlx_texture_t	*down1;
	mlx_texture_t	*down2;
	mlx_texture_t	*up;
	mlx_texture_t	*up1;
	mlx_texture_t	*up2;
	mlx_texture_t	*right;
	mlx_texture_t	*right1;
	mlx_texture_t	*right2;
	mlx_texture_t	*left;
	mlx_texture_t	*left1;
	mlx_texture_t	*left2;
	mlx_texture_t	*defleft;
	mlx_texture_t	*defright;
	mlx_texture_t	*defup;
	mlx_texture_t	*defdown;
	mlx_texture_t	*groundimg;
	mlx_texture_t	*wallimg;
	mlx_texture_t	*coinimg;
	mlx_texture_t	*exitimg;
	mlx_texture_t	*enemyimg;
}t_map;

int		checkarg(char *s);
char	*mapline(char *str);
int		amountofchar(char *v, char c);
int		checkmap(char *v);
int		filledwithone(char *s);
int		startandend1(char *s);
int		samelengh(char **s);
int		map2dcheck(char **s);
int		ft_doublelen(char **s);
int		*whereisit(char **p, char c);
void	backtrack(char **v, int *s);
void	fillstruct(t_map *struc, char *v);
int		check_mapcpy(char **v);
void	fillimages(t_map *map);
void	moveup(t_map *map);
void	movedown(t_map *map);
void	moveright(t_map *map);
void	moveleft(t_map *map);
void	defence(t_map *map);
void	printbackground(t_map *map);
void	printcoin(t_map *map);
int		canmoveup(t_map *map);
int		canmovedown(t_map *map);
int		canmoveright(t_map *map);
int		canmoveleft(t_map *map);
void	coinposition(t_map *map);
void	printexit(t_map *map);
int		howmanycoins(t_map *map);
void	khroj(t_map *map);
void	counter(t_map *map);
void	freemap(t_map *map);
#endif
