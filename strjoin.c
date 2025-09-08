/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:13 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:49 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *s1, char *s2, char *join)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
}

void	ft_strcat3(char *s1, char *s2, char *s3, char *join)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	while (s3[k])
	{
		join[i + j + k] = s3[k];
		k++;
	}
	join[i + j + k] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = NULL;
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	ft_strcat(s1, s2, new);
	return (new);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char		*new;
	size_t		len1;
	size_t		len2;
	size_t		len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	new = NULL;
	new = malloc(sizeof(char) * (len1 + len2 + len3 + 1));
	if (new == NULL)
		return (NULL);
	ft_strcat3(s1, s2, s3, new);
	return (new);
}
