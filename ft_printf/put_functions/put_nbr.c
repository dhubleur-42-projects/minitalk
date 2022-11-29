/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:53:16 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:53:16 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			length;
	long int	cpy;

	length = 1;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		printf_putchar_fd('-', fd);
		length++;
	}
	cpy = nbr;
	while (cpy >= 10)
	{
		cpy /= 10;
		length++;
	}
	if (nbr >= 10)
		printf_putnbr_fd(nbr / 10, fd);
	printf_putchar_fd((nbr % 10) + '0', fd);
	return (length);
}

int	printf_putnbr_hexa_cap_fd(unsigned int n, int fd)
{
	int				length;
	char			*base;
	unsigned int	cpy;

	base = "0123456789ABCDEF";
	length = 1;
	cpy = n;
	while (cpy >= 16)
	{
		cpy /= 16;
		length++;
	}
	if (n >= 16)
		printf_putnbr_hexa_cap_fd(n / 16, fd);
	printf_putchar_fd(base[n % 16], fd);
	return (length);
}

int	printf_putnbr_hexa_fd(unsigned int n, int fd)
{
	int				length;
	char			*base;
	unsigned int	cpy;

	base = "0123456789abcdef";
	length = 1;
	cpy = n;
	while (cpy >= 16)
	{
		cpy /= 16;
		length++;
	}
	if (n >= 16)
		printf_putnbr_hexa_fd(n / 16, fd);
	printf_putchar_fd(base[n % 16], fd);
	return (length);
}

int	printf_putulnbr_hexa_fd(unsigned long int n, int fd)
{
	int					length;
	char				*base;
	unsigned long int	cpy;

	base = "0123456789abcdef";
	length = 1;
	cpy = n;
	while (cpy >= 16)
	{
		cpy /= 16;
		length++;
	}
	if (n >= 16)
		printf_putulnbr_hexa_fd(n / 16, fd);
	printf_putchar_fd(base[n % 16], fd);
	return (length);
}

int	printf_putunbr_fd(unsigned int n, int fd)
{
	int				length;
	unsigned int	cpy;

	length = 1;
	cpy = n;
	while (cpy >= 10)
	{
		cpy /= 10;
		length++;
	}
	if (n >= 10)
		printf_putunbr_fd(n / 10, fd);
	printf_putchar_fd((n % 10) + '0', fd);
	return (length);
}
