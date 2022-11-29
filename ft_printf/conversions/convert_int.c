/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:10:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:52:17 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_flags flags, va_list *ap)
{
	int	chars;
	int	nb;

	nb = va_arg(*ap, int);
	va_end(*ap);
	chars = 0;
	if (flags.plus)
	{
		if (nb >= 0)
		{
			chars++;
			printf_putchar_fd('+', 1);
		}
	}
	else if (flags.space)
	{
		if (nb >= 0)
		{
			chars++;
			printf_putchar_fd(' ', 1);
		}
	}
	chars += printf_putnbr_fd(nb, 1);
	return (chars);
}
