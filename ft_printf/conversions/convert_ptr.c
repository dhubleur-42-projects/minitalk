/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:18:07 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:57:21 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(t_flags flags, va_list *ap)
{
	unsigned long int	ptr;
	int					chars;

	chars = 0;
	ptr = va_arg(*ap, unsigned long int);
	va_end(*ap);
	if (ptr)
	{
		if (flags.plus)
		{
			printf_putchar_fd('+', 1);
			chars++;
		}
		else if (flags.space)
		{
			printf_putchar_fd(' ', 1);
			chars++;
		}
		printf_putstr_fd("0x", 1);
		chars += 2;
		chars += printf_putulnbr_hexa_fd(ptr, 1);
		return (chars);
	}
	printf_putstr_fd("0x0", 1);
	return (3);
}
