/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:24:10 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:52:59 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	va_end(*ap);
	if (str == NULL)
	{
		printf_putstr_fd("(null)", 1);
		return (6);
	}
	printf_putstr_fd(str, 1);
	return (printf_strlen(str));
}
