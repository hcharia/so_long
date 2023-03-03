/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:38 by hcharia           #+#    #+#             */
/*   Updated: 2022/11/17 14:50:13 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stat = readfile(stat, fd);
	if (!stat)
		return (NULL);
	line = takeline(stat);
	stat = rest(stat);
	return (line);
}
