/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:32:14 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/05 10:27:42 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

char	get_char_from_byte(t_read read)
{
	char	character;
	int		binary;
	int		i;

	character = 0;
	i = 0;
	binary = 128;
	while (binary)
	{
		character += read.char_read[i] * binary;
		i++;
		binary >>= 1;
	}
	return (character);
}

int	main(void)
{
	int			pid;
	t_sigation	sa;

	ft_printf("Welcome to the Minitalk's server ! Starting ...\n");
	reset_char_read();
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Server started ! You can send me a message with the PID %i !\n\n",
		pid);
	while (TRUE)
		;
}
