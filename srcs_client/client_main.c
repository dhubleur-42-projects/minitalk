/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:36:14 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/05 09:51:31 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

t_send	g_send_infos;

void	send_error(void)
{
	ft_printf("Error encountered during the message's transmission. ");
	ft_printf("This is probably due to a bad PID\n");
	exit(1);
}

void	send_next_byte(int pid, unsigned char c)
{
	if (c & g_send_infos.binary)
	{
		if (kill(pid, SIGUSR2) == -1)
			send_error();
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			send_error();
	}
	g_send_infos.binary >>= 1;
}

void	send_next_char(void)
{
	g_send_infos.binary = 128;
	if (g_send_infos.current == -1)
	{
		ft_printf("The whole message whas received by the server !\n");
		exit(0);
	}
	send_next_byte(g_send_infos.pid,
		(unsigned char) g_send_infos.str[g_send_infos.current]);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("The server notified an error during message's reception !\n");
		exit(1);
	}
	if (signum == SIGUSR2)
	{
		if (g_send_infos.binary == 0)
		{
			if (g_send_infos.str[g_send_infos.current] == '\0')
				g_send_infos.current = -1;
			else
				g_send_infos.current = g_send_infos.current + 1;
			send_next_char();
		}
		else
			send_next_byte(g_send_infos.pid,
				g_send_infos.str[g_send_infos.current]);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Please use client with this format: ");
		ft_printf("./client SERVER_PID \"MESSAGE\"\n");
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	g_send_infos.pid = ft_atoi(argv[1]);
	g_send_infos.str = argv[2];
	g_send_infos.current = 0;
	if (g_send_infos.str[0])
		ft_printf("Sending message to PID %i ...\n", g_send_infos.pid);
	else
		ft_printf("Sending quit signal to PID %i ...\n", g_send_infos.pid);
	send_next_char();
	while (TRUE)
		;
}
