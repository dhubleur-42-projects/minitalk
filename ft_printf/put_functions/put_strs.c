/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:50:13 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 20:50:13 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	printf_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, printf_strlen(s));
}

size_t	printf_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
