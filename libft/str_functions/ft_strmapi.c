/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:19:50 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/24 11:48:19 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	int		i;

	if (!s)
		return (NULL);
	mapped = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapped)
		return (NULL);
	i = -1;
	while (s[++i])
		mapped[i] = (*f)(i, s[i]);
	mapped[i] = '\0';
	return (mapped);
}
