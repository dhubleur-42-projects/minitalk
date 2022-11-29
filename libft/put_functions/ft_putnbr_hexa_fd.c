/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:46:04 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/05 20:46:04 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa_fd(unsigned int n, int cap, int fd)
{
	int				length;
	char			*base;
	unsigned int	cpy;

	if (cap)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	length = 1;
	cpy = n;
	while (cpy >= 16)
	{
		cpy /= 16;
		length++;
	}
	if (n >= 16)
		ft_putnbr_hexa_fd(n / 16, cap, fd);
	ft_putchar_fd(base[n % 16], fd);
	return (length);
}
