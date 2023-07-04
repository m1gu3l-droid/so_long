/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:44:38 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:44:39 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strchr_gnl(const char *s, int c)
{
	int		index;
	int		len;

	index = 0;
	len = 0;
	if (c == '\0')
		return (0);
	while (s[index] != '\0')
	{
		if (s[index] == c)
			len++;
		index++;
	}
	return (len);
}
