/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:24:02 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/26 14:25:26 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len && little[j] && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && big[i + j])
			j++;
		if (little[j])
			i++;
	}
	if (little[j])
		return (NULL);
	return ((char *)&big[i]);
}
