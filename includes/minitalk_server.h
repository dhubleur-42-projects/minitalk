/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:30:45 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/05 09:59:18 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include "libft.h"
# include "ft_printf.h"

# include <signal.h>

typedef struct sigaction	t_sigation;

typedef struct s_dynamic_buffer
{
	char	*buffer;
	int		i;
	int		size;
}	t_dynamic_buffer;

typedef struct s_read
{
	int					char_read[8];
	t_dynamic_buffer	buffer;
}	t_read;

t_dynamic_buffer	init_buffer(void);
t_dynamic_buffer	append(t_dynamic_buffer buffer, char c);
t_dynamic_buffer	print_content_and_reset(t_dynamic_buffer buffer, int pid);
void				reset_char_read(void);
void				append_char_received(char c, int pid);
void				make_read(int signum, int current, int pid);
void				init_on_signal(int pid);
void				signal_handler(int signum, siginfo_t *siginfo,
						void *ucontext);
char				get_char_from_byte(t_read read);

#endif