/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:45:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/15 05:14:27 by fnovais-         ###   ########.fr       */
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
# define COL "./images/collect.xpm"
# define MFD "./images/me_food.xpm"

# define KUP 65362
# define KDOWN 65364
# define KLEFT 65361
# define KRIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_img
{
	void	*i_wall;
	void	*i_floor;
	void	*i_player;
	void	*i_exit;
	void	*i_collect;
	void	*i_me_food;
	void	*i_tr;
	void	*i_tl;
	void	*i_br;
	void	*i_bl;
	void	*i_l;
	void	*i_r;
	void	*i_t;
	void	*i_b;
}				t_img;

typedef struct s_game
{
	t_img		pics;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			collect;
	int			val_col;
	int			score;
	int			player;
	int			player_x;
	int			player_y;
	int			moves;
	int			exit;
	int			dying;
	int			temp;
	int			path;
	char		**layout;
	char		**lay_back;
}				t_game;

//so_long
void	check_args(char **av);
void	start_map(t_game *game);
void	start_game(t_game *game);

// read_map
size_t	ft_strlen_rm(const char *s);
void	read_map(t_game *game, int fd);

// start_position
void	start_position(t_game *game);

// render_img
void	image_to_map(int x, int y, char c, t_game *game);
void	render_sprite(t_game *game);

// access_img
void	access_sprite(t_game *game);

// closure
void	free_layout(t_game *game);
void	free_layback(t_game *game);
void	free_sprite(t_game *game);
void	quit_game(char *str, t_game *game);
int		closure(t_game *game);

//control key
int		val_move(t_game *game, int y, int x, int key);
void	input_move(t_game *game, int y, int x, int key);
int		control_key(int key, t_game *game);

// val_path
bool	val_path(t_game *game, int x, int y);
bool	val_path_param(t_game *game);

// validations
int		val_rectangular(t_game *game);
int		val_vault(t_game *game);
int		val_characters(t_game *game);
void	validations(t_game *game);

// get_dimensions
int		ft_strlen_width(char *str);
void	get_dimensions(t_game *game, int fd);

// ft_strchr_gnl
size_t	ft_strlen_gnl(const char *s);

// get_next_line
char	*next_line(char *s1);
char	*read_line(int fd, char *s1);
char	*get_next_line(int fd);

// get_next_line_utils
char	*ft_cpy(char *dst);
char	*ft_strchr_g(const char	*s, int c);
char	*ft_join(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);

#endif
