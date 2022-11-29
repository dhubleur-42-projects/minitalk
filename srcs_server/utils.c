/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:54:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/05 09:59:35 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

t_read	g_read;

void	reset_char_read(void)
{
	g_read.char_read[0] = -1;
	g_read.char_read[1] = -1;
	g_read.char_read[2] = -1;
	g_read.char_read[3] = -1;
	g_read.char_read[4] = -1;
	g_read.char_read[5] = -1;
	g_read.char_read[6] = -1;
	g_read.char_read[7] = -1;
}

void	append_char_received(char c, int pid)
{
	g_read.buffer = append(g_read.buffer, c);
	if (!(g_read.buffer.buffer))
	{
		ft_printf("An error occurred while decoding\n");
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("Unable to send error to client\n");
		exit(1);
	}
}

void	make_read(int signum, int current, int pid)
{
	char	c;

	if (signum == SIGUSR1)
		g_read.char_read[current] = 0;
	if (signum == SIGUSR2)
		g_read.char_read[current] = 1;
	if (current == 7)
	{
		c = get_char_from_byte(g_read);
		if (c == '\0')
		{
			ft_printf("     ===== Received a message from %i =====     \n\n",
				pid);
			g_read.buffer = print_content_and_reset(g_read.buffer, pid);
			ft_putchar_fd('\n', 1);
			ft_putchar_fd('\n', 1);
		}
		else
			append_char_received(c, pid);
		reset_char_read();
	}
}

void	init_on_signal(int pid)
{
	if (!(g_read.buffer.buffer))
	{
		g_read.buffer = init_buffer();
		if (!(g_read.buffer.buffer))
		{
			ft_printf("An error occurred while reading\n");
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("Unable to send error to client\n");
			exit(1);
		}
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	int		current;
	int		i;
	int		pid;

	(void) ucontext;
	pid = siginfo->si_pid;
	init_on_signal(pid);
	i = -1;
	while (++i < 8)
	{
		if (g_read.char_read[i] == -1)
		{
			current = i;
			break ;
		}
	}
	make_read(signum, current, pid);
	if (kill(pid, SIGUSR2) == -1)
		ft_printf("Unable to send confirmation to client\n");
}
