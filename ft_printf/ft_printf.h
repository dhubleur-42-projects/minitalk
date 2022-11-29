/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:10:42 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/12 12:43:55 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags {
	int	alternate;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *str, ...);

int		print_conversion(char conv, t_flags flags, va_list *ap);
int		is_conversion(char c);

int		print_char(va_list *ap);
int		print_str(va_list *ap);
int		print_ptr(t_flags flags, va_list *ap);
int		print_dbl(t_flags flags, va_list *ap);
int		print_int(t_flags flags, va_list *ap);
int		print_uint(va_list *ap);
int		print_hex(t_flags flags, va_list *ap);
int		print_hex_cap(t_flags flags, va_list *ap);

t_flags	init_flags(void);
int		is_flag(char c);
int		is_already_flag(t_flags flags, char c);
int		check_flags(const char *str, int i, t_flags *flags);

int		printf_putnbr_fd(int n, int fd);
int		printf_putnbr_hexa_cap_fd(unsigned int n, int fd);
int		printf_putnbr_hexa_fd(unsigned int n, int fd);
int		printf_putulnbr_hexa_fd(unsigned long int n, int fd);
int		printf_putunbr_fd(unsigned int n, int fd);
void	printf_putchar_fd(char c, int fd);
void	printf_putstr_fd(char *s, int fd);
size_t	printf_strlen(const char *s);

#endif