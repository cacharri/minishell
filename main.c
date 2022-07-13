/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:36:59 by ialvarez          #+#    #+#             */
/*   Updated: 2022/07/13 20:09:23 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	syntax_char(char *ch, int fd)
{
	char	*s;

	s = ft_strdup("-minishell: syntax error near unexpected token ");
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	write(fd, "`", 1);
	if (ch != NULL)
		write(fd, ch, ft_strlen(ch));
	write(fd, "\'\n", 2);
	return (1);
}

char	*get_promt(char *user, t_data *data)
{
	if (user != NULL)
		data->env_user = strdup(user);
	else
		data->env_user = strdup("ghost");
	return (ft_strjoin(data->env_user, "@minishell: $ "));
}
/*
int	pipe_parse(t_data *data)
{
	char	**aux;
	int		j;
	int		i;
	int		count;

	j = -1;
	while (data->spt_pipes[++j] != NULL)
	{
		aux = st_split(data->spt_pipes[j], ' ');
		i = -1;
		count = 0;
		while (aux[++i] != NULL)
		{
			if (aux[i][0] == '\0')
				count++;
		}
		if (i == count)
		{
			syntax_char(ft_charjoin('|'), STDERR_FILENO);
			free(aux);
			return (1);
		}
		free(aux);
	}
	return (0);
}

int	even_quotes(char *s, int count, char x)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			count++;
			if (s[i] == '\'')
				x = '\'';
			else
				x = '\"';
			i++;
			while (s[i] != x && s[i] != '\0')
				i++;
			if (s[i] == x)
				count++;
		}
		if (count % 2 != 0)
			return (syntax_char(ft_charjoin(x), STDERR_FILENO));
	}
	if (--i && s[i] == '|')
		return (syntax_char(ft_charjoin('|'), STDERR_FILENO));
	return (0);
}
*/
int	main(void) /* get_env */
{
	t_data	data;
	char	*cmd_line;

	/*atexit(leaks);*/
	while (1)
	{
		data.promt = get_promt(getenv("USER"), &data);
		cmd_line = readline (data.promt);
		if (even_quotes(cmd_line, 0, 0) == 0)
		{
			data.spt_pipes = st_split(cmd_line, '|');
			if (pipe_parse(&data) == 0)
				printf("countinua\n");
		}
		free (cmd_line);
	}
}
