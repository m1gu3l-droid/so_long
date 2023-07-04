/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_upperhexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:45:50 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:45:52 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_upperhexa(long long nbr)
{
	int		size;
	char	*base;

	size = 0;
	base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		size = write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 16)
	{
		size += ft_putnbr_upperhexa((nbr / 16));
		size += ft_putnbr_upperhexa((nbr % 16));
	}
	else
		size += ft_putchar(base[nbr]);
	return (size);
}
