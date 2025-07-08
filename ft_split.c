/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:13:11 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 12:55:37 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
		i++;
	}
	return (count);
}

int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

void	free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = malloc(len_word(s, c) * sizeof(char) + 1);
			if (!result[i])
				return (free_all(result, i), NULL);
			ft_strlcpy(result[i], s, len_word(s, c) + 1);
			s += len_word(s, c);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
