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

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, int c)
{
	int		index;
	int		len;

	index = 0;
	len = 0;
//	len = ft_strlen_gnl(s);
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
/*
int	main(void)
{
		char	src[] = "tdgvdvydljjd";
		char	ch = 'y';
		char	*ptr = ft_strchr(src, ch);

		printf("%s\n%s\n", ptr, strchr(src, ch));
		return 0;
}
*/
