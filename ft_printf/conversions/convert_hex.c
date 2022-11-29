/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:10:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:52:05 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(t_flags flags, va_list *ap)
{
	int	chars;

	chars = 0;
	if (flags.alternate)
	{
		printf_putstr_fd("0x", 1);
		chars += 2;
	}
	chars += printf_putnbr_hexa_fd(va_arg(*ap, unsigned int), 1);
	va_end(*ap);
	return (chars);
}
