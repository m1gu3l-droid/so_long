/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:52:36 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/03 03:54:01 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long"

//is map rectangular?

//is map surrounded by walls?

//does map have only 1 player?

//does map have one or more collectibles?

//does map have only one exit?

//does map have a valid path?


	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		b = ft_strlen(line);
		map.layout[a] = malloc(sizeof(char) * b + 1);
		map.layout[a] = line;
		ft_printf("%s", map.layout[a]);
		free(line);
		a++;
	}
