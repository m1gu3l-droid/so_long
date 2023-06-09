/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:45:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 21:20:20 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		collect;
	int		player;
	int		exit;
	char	**layout;
}	t_map;

void	read_map(t_map *game, int fd);

size_t	ft_strlen_gnl(const char *s);
void	get_height(t_map *game, int fd);
void	get_width(t_map *game, int fd);
char	*next_line(char *s1);
char	*read_line(int fd, char *s1);
char	*get_next_line(int fd);
char	*ft_cpy(char *dst);
char	*ft_strchr(const char	*s, int c);
char	*ft_join(char *s1, char *s2);
int	ft_strchr_gnl(const char *s, int c);
#endif
