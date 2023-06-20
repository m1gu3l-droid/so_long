/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:06:17 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/14 12:50:22 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
