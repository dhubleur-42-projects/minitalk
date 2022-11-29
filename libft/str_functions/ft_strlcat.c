/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:19:20 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/23 10:30:33 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	i = 0;
	while (i < size - dest_len && src[i])
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	if (i + dest_len < size)
		dst[i + dest_len] = '\0';
	else
		dst[i + dest_len - 1] = '\0';
	return (dest_len + src_len);
}
