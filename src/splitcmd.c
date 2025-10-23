/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:09 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:47 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	arg_len(const char *s)
{
	int		i;
	char	quote;

	i = 0;
	if (is_quote(s[i]))
	{
		quote = s[i];
		i++;
		while (s[i] && s[i] != quote)
			i++;
		if (s[i] == quote)
			i++;
	}
	else
	{
		while (s[i] && s[i] != ' ' && !is_quote(s[i]))
			i++;
	}
	return (i);
}

int	count_args(const char *cmd)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ')
			i++;
		if (cmd[i])
		{
			count++;
			len = arg_len(&cmd[i]);
			i += len;
		}
	}
	return (count);
}

char	*copy_arg(const char *src, int len)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (is_quote(src[0]))
	{
		i = 1;
		while (i < len - 1)
			res[j++] = src[i++];
	}
	else
	{
		while (i < len)
			res[j++] = src[i++];
	}
	res[j] = '\0';
	return (res);
}

char	**split_cmd_while(const char *cmd, char **argv)
{
	int	i;
	int	arg;
	int	len;

	i = 0;
	arg = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ')
			i++;
		if (cmd[i])
		{
			len = arg_len(&cmd[i]);
			argv[arg] = copy_arg(&cmd[i], len);
			if (!argv[arg])
				return (NULL);
			arg++;
			i += len;
		}
	}
	argv[arg] = NULL;
	return (argv);
}
