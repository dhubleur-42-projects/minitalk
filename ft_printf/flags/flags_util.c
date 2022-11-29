/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:25:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/12 12:43:49 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '#')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '+')
		return (1);
	return (0);
}

int	is_already_flag(t_flags flags, char c)
{
	if (c == '#' && flags.alternate)
		return (1);
	if (c == ' ' && flags.space)
		return (1);
	if (c == '+' && flags.plus)
		return (1);
	return (0);
}

int	check_flags(const char *str, int i, t_flags *flags)
{
	int	j;

	j = 1;
	*flags = init_flags();
	while (str[i + j] && is_flag(str[i + j])
		&& !is_already_flag(*flags, str[i + j]))
	{
		if (str[i + j] == '#')
			flags->alternate = 1;
		if (str[i + j] == ' ')
			flags->space = 1;
		if (str[i + j] == '+')
			flags->plus = 1;
		j++;
	}
	if (is_conversion(str[i + j]))
	{
		return (j);
	}
	return (0);
}
