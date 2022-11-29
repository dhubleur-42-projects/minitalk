/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:20:31 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/05 09:59:41 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

t_dynamic_buffer	init_buffer(void)
{
	t_dynamic_buffer	buffer;

	buffer.buffer = malloc(sizeof(char) * 50);
	buffer.i = 0;
	buffer.size = 50;
	return (buffer);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	i--;
	while (++i < n)
		dest[i] = 0;
	return (dest);
}

t_dynamic_buffer	append(t_dynamic_buffer buffer, char c)
{
	char	*tmp;

	if (buffer.i == buffer.size)
	{
		tmp = malloc(sizeof(char) * (buffer.size * 2));
		if (!tmp)
		{
			free(buffer.buffer);
			buffer.buffer = NULL;
			return (buffer);
		}
		ft_strncpy(tmp, buffer.buffer, buffer.size);
		free(buffer.buffer);
		buffer.buffer = tmp;
		buffer.size = buffer.size * 2;
	}
	buffer.buffer[buffer.i++] = c;
	return (buffer);
}

t_dynamic_buffer	print_content_and_reset(t_dynamic_buffer buffer, int pid)
{
	int	i;

	i = -1;
	if (buffer.i == 0)
	{
		ft_printf("                 (Quit signal)\n\n");
		if (kill(pid, SIGUSR2) == -1)
			ft_printf("Unable to send confirmation to client\n");
		free(buffer.buffer);
		ft_printf("See you next !\n");
		exit(0);
	}
	while (++i < buffer.i)
		ft_putchar_fd(buffer.buffer[i], 1);
	free(buffer.buffer);
	buffer.buffer = NULL;
	return (buffer);
}
