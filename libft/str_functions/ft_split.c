/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:58:43 by dhubleur          #+#    #+#             */
/*   Updated: 2021/11/30 16:55:44 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i + 1] == c || str[i + 1] == '\0')
		{
			words++;
			while (str[i + 1] != '\0' && str[i + 1] == c)
				i++;
		}
		i++;
	}
	return (words);
}

char	*get_word(const char *str, int start, int stop)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (stop - start + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < (stop - start))
		word[i] = str[start + i];
	word[i] = '\0';
	return (word);
}

char	**free_all(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
	return (NULL);
}

void	skip_first_separators(const char *str, char c, int *i, int *start)
{
	*i = 0;
	while (str[*i] && str[*i] == c)
		(*i)++;
	*start = *i;
	*i = *i - 1;
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		i;
	int		word;
	int		start;

	split = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!split)
		return (NULL);
	word = 0;
	skip_first_separators(str, c, &i, &start);
	while (str[++i])
	{
		if (str[i + 1] == c || str[i + 1] == '\0')
		{
			split[word] = get_word(str, start, i + 1);
			if (!split[word++])
				return (free_all(split));
			while (str[i + 1] != '\0' && str[i + 1] == c)
				start = ++i + 1;
		}
	}
	split[word] = NULL;
	return (split);
}
