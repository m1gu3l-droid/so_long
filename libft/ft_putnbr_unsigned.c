/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:45:40 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:45:42 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putnbr_unsigned(long long n)
{
	unsigned int	nbr;
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		nbr = (4294967295 - n) + 1;
		size = ft_putnbr(nbr);
	}
	else
		size = ft_putnbr(n);
	return (size);
}
