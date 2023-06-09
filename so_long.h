/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:45:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/03 04:06:26 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		n_collect;
	int		n_player;
	int		n_exit;
	char	**layout;
}	t_map;

#endif
