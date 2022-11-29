/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:30:45 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/13 16:36:40 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include "libft.h"
# include "ft_printf.h"

# include <signal.h>

typedef struct s_send
{
	char	*str;
	int		current;
	int		pid;
	int		binary;
}	t_send;

#endif