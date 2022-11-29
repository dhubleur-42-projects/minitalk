/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:10:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:52:53 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uint(va_list *ap)
{
	int	chars;

	chars = printf_putunbr_fd(va_arg(*ap, unsigned int), 1);
	va_end(*ap);
	return (chars);
}
