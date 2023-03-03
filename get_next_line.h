/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:09:05 by hcharia           #+#    #+#             */
/*   Updated: 2023/02/15 12:07:55 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

int		my_strchr(char *s, char a);
char	*get_next_line(int fd);
char	*my_strjoin(char *s1, char *s2);
char	*readfile(char *stat, int fd);
char	*takeline(char *stat);
char	*rest(char *stat);
int		ft_doublelen(char **s);
#endif