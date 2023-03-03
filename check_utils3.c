/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:16:19 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:33:22 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	backtrack(char **v, int *s)
{	
	int	b[2];

	b[0] = s[0];
	b[1] = s[1];
	v[s[0]][s[1]] = 'X';
	if (v[s[0]][s[1] - 1] != '1' && v[s[0]][s[1] - 1] != 'X')
		s[1]--;
	else if (v[s[0]][s[1] + 1] != '1' && v[s[0]][s[1] + 1] != 'X')
		s[1]++;
	else if (v[s[0] + 1][s[1]] != '1' && v[s[0] + 1][s[1]] != 'X')
		s[0]++;
	else if (v[s[0] - 1][s[1]] != '1' && v[s[0] - 1][s[1]] != 'X')
		s[0]--;
	else
		return ;
	backtrack(v, s);
	backtrack(v, b);
}

void	fillstruct(t_map *struc, char *v)
{
	struc->v = mapline(v);
	if (!struc->v)
		exit(2);
	struc->mapg = ft_split(struc->v, '\n');
	struc->cpymapg = ft_split(struc->v, '\n');
	struc->pos_p = whereisit(struc->mapg, 'P');
	struc->pos_e = whereisit(struc->mapg, 'E');
	if (struc->pos_p)
	{
		struc->px = struc->pos_p[1] * 100;
		struc->py = struc->pos_p[0] * 100;
	}
	struc->hight = ft_doublelen(struc->mapg) * 100;
	struc->width = ft_strlen(struc->mapg[0]) * 100;
	struc->numcoins = howmanycoins(struc);
	struc->numcoins = howmanycoins(struc);
}

int	check_mapcpy(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == 'P' || v[i][j] == 'E' || v[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
