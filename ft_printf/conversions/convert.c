/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:23:20 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/12 12:43:49 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion(char conv, t_flags flags, va_list *ap)
{
	if (conv == 'c')
		return (print_char(ap));
	if (conv == 's')
		return (print_str(ap));
	if (conv == 'p')
		return (print_ptr(flags, ap));
	if (conv == 'd')
		return (print_dbl(flags, ap));
	if (conv == 'i')
		return (print_int(flags, ap));
	if (conv == 'u')
		return (print_uint(ap));
	if (conv == 'x')
		return (print_hex(flags, ap));
	if (conv == 'X')
		return (print_hex_cap(flags, ap));
	return (0);
}

int	is_conversion(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	return (0);
}
