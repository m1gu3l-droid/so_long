/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:45:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/12 03:32:28 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx/mlx.h"
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
# include <stdbool.h>

# define WALL "./images/wall.xpm"
# define FLOOR "./images/floor.xpm"
# define PLAYER "./images/player.xpm"
# define EXIT "./images/exit.xpm"
# define COLLECT "./images/collect.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef	struct	s_pic
{
	void	*i_wall;
	void	*i_floor;
	void	*i_player;
	void	*i_exit;
	void	*i_collect;
}				t_pic;

typedef struct s_map
{
	t_pic		pics;
	void		*mlx;
	void		*win;
	int		width;
	int		height;
	int		collect;
	int		score;
	int		player;
	int		player_x;
	int		player_y;
	int		moves;
	int		exit;
	int		dying;
	char		**layout;
	char		**lay_back;
}				t_map;

//so_long
void	check_args(t_map *game, int ac, char **av);
void	start_map(t_map *game);
void	start_game(t_map *game);

// read_map
size_t	ft_strlen_rm(const char *s);
void	read_map(t_map *game, int fd);

// start_position
void	start_position(t_map *game);

// render_img
void	image_to_map(int x, int y, char c, t_map *game);
void	render_img(t_map *game);

// access_img
void	access_img(t_map *game);

// closure
void	quit_game(char *str, t_map *game);
int	closure(t_map *game);

// free_ft
void	free_map(t_map *game);
void	free_sprite(t_map *game);
void	free_player(t_map *game);

//control key
int	val_move(t_map *game, int y, int x, int key);
void	input_move(t_map *game, int y, int x, int key);
int	control_key(int key, t_map *game);

// validations
int	val_rectangular(t_map *game);
int	val_vault(t_map *game);
int	val_characters(t_map *game);
bool	val_path(t_map *game, char c, int x, int y);
int	val_path_param(t_map *game);
void	validations(t_map *game);

// get_dimensions
int	ft_strlen_width(char *str);
void	get_dimensions(t_map *game, int fd);

// ft_strchr_gnl
size_t	ft_strlen_gnl(const char *s);

// get_next_line
char	*next_line(char *s1);
char	*read_line(int fd, char *s1);
char	*get_next_line(int fd);

// get_next_line_utils
char	*ft_cpy(char *dst);
char	*ft_strchr(const char	*s, int c);
char	*ft_join(char *s1, char *s2);
int	ft_strchr_gnl(const char *s, int c);

#endif
