/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:58:10 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 10:54:10 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			length;
	long int	cpy;

	length = 1;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
		length++;
	}
	cpy = nbr;
	while (cpy >= 10)
	{
		cpy /= 10;
		length++;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
	return (length);
}
