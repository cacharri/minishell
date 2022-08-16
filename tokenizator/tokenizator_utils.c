/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:47:53 by vifernan          #+#    #+#             */
/*   Updated: 2022/08/16 13:23:18 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strint(const char *s, char c)
{
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(s);
	while (a < len + 1)
	{
		if (s[a] == c)
			return (a);
		a++;
	}
	return (-1);
}

char	*ret_key(char *str, int i, int j, char c)
{
	char	lock;
	char	*ret;

	lock = 0;
	ret = malloc(sizeof(char) * j + 1);
	j = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] == '<' || str[i] == '>') && lock == 0)
			break ;
		if ((str[i] == '\'' || str[i] == '\"') && (c == 0 && lock == 0))
		{
			if (str[i] == '\'')
				c = '\'';
			else
				c = '\"';
			lock = 1;
		}
		else if ((c == '\'' || c == '\"') && str[i] == c && lock == 1)
		{
			c = 0;
			lock = 0;
		}
		else if ((str[i] != '\'' && str[i] != '\"') || lock == 1)
			ret[j++] = str[i];
	}
	ret[j] = '\0';
	return (ret);
}

char	*find_key(char *str, int i, int j)
{
	char	c;
	int		lock;

	c = '\0';
	lock = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] == '<' || str[i] == '>') && lock == 0)
			break ;
		if ((str[i] == '\'' || str[i] == '\"') && (c == 0 && lock == 0))
		{
			if (str[i] == '\'')
				c = '\'';
			else
				c = '\"';
			lock = 1;
		}
		else if ((c == '\'' || c == '\"') && str[i] == c && lock == 1)
		{
			c = 0;
			lock = 0;
		}
		else if ((str[i] != '\'' && str[i] != '\"') || lock == 1)
			j++;
	}
	return (ret_key(str, -1, j, '\0'));
}


char	**cmd_arg_quottes(char	*pipe)
{
	char	**aux_cmd;
	char	*aux;
	int		x;
	int		j;

	aux = NULL;
	j = 0;
	if (!pipe)
		return (NULL);
	aux_cmd = spqu_split(skip_spaces(pipe), ' ');
	x = -1;
	while (aux_cmd[++x] != NULL)
	{
		if (aux_cmd[x][0] != '$' && find_rm_size(aux_cmd[x], 0, &j) == (int)ft_strlen(aux_cmd[x]))
			aux = skip_quotes(skip_spaces(aux_cmd[x]));
		else
			aux = skip_spaces(aux_cmd[x]);
		free(aux_cmd[x]);
		aux_cmd[x] = aux;
	}
	return (aux_cmd);
}

int	find_heredoc(char **cmd_sp, int i, int type)
{
	int		lock;
	int		flag;

	if (!cmd_sp)
		return (-1);
	flag = 0;
	if (i == 0)
	{
		i = -1;
		flag = 1;
	}
	lock = 0;
	while (cmd_sp[++i] != NULL)
	{
		if (ft_strnstr(cmd_sp[i], "<<", 2) || ft_strnstr(cmd_sp[i], "<", 1)
			|| ft_strnstr(cmd_sp[i], ">>", 2) || ft_strnstr(cmd_sp[i], ">", 1) 
			|| find_rm_size(cmd_sp[i], 0, &lock) != (int)ft_strlen(cmd_sp[i]))
			break ;
	}
	if (cmd_sp[i] == NULL)
	{
		if (flag > 0)
			free_matrix(cmd_sp);
		return (-1);
	}
	if (type == 0)
	{
		type = find_rm_size(cmd_sp[i], 0, &lock);
		if (type == (int)ft_strlen(cmd_sp[i]) || (cmd_sp[i][type] != '<' || cmd_sp[i][type + 1] != '<'))
			return (-1);
	}
	if (flag > 0)
			free_matrix(cmd_sp);
	return (i);
}

char	*ft_strjoin_swap(char	*ret, char	*str)
{
	char	*aux;

	if (!ret)
		return (ft_strdup(str));
	else
	{
		aux = ft_strdup(ret);
		free(ret);
		ret = ft_strjoin(aux, str);
		free (aux);
	}
	return (ret);
}

int		find_rm_size(char *str, int i, int *lock)
{
	char	c;

	c = '\0';
	*lock = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] == '<' || str[i] == '>') && *lock % 2 == 0)
			break ;
		if ((str[i] == '\'' || str[i] == '\"') && (c == '\0' && *lock % 2 == 0))
		{
			if (str[i] == '\'')
				c = '\'';
			else
				c = '\"';
			*lock += 1;
		}
		else if ((c == '\'' || c == '\"') && str[i] == c)
		{
			c = '\0';
			*lock += 1;
		}
		i++;
	}
	return (i);
}

char	*find_middle(char *str, int lock)
{
	int i;
	int	init;
	int	count;
	int	end;
	
	
	i = -1;
	count = 0;
	init = find_rm_size(str, 0, &lock);
	while (str[init + count] == '>' || str[init + count] == '<')
		count++;
	end = find_rm_size((char *)str + init + count, 0, &lock);
	return(ft_strjoin(ft_strjoin(ft_substr(str, 0, init), " "),
					(char *)str + end + init + count));
}


char	*rm_heredoc(char **cmd_sp, int i, int f, int lock)
{
	char	*ret;
	int		x;
	int		flag;
	int		start;

	x = -1;
	(void)f;
	ret = NULL;
	flag = 0;
	while (cmd_sp[++x] != NULL)
	{
		lock = 0;
		if ( x  == i && (((ft_strnstr(cmd_sp[x], ">>", 2) || (ft_strnstr(cmd_sp[x], "<<", 2))) && (int)ft_strlen(cmd_sp[x]) == 2)
				|| (ft_strnstr(cmd_sp[x], ">", 1) && (int)ft_strlen(cmd_sp[x]) == 1)))
		{
			start = find_rm_size(cmd_sp[x + 1], 0, &lock) + lock;
			if (start)
				ret = ft_strjoin_swap(ret, ft_substr(cmd_sp[x + 1], start - lock, (int)ft_strlen(cmd_sp[x + 1]) - (start - lock)));
			x++;
			if (cmd_sp[x] == NULL)
				break ;
		}
		else if (x == i && ((ft_strnstr(cmd_sp[x], ">>", 2) || (ft_strnstr(cmd_sp[x], "<<", 2))) && (int)ft_strlen(cmd_sp[x]) > 2))
		{
			start = find_rm_size((char *)cmd_sp[x] + 2, 0, &lock);
			if (start)
				ret = ft_strjoin_swap(ret, ft_substr(cmd_sp[x], start + 2, (int)ft_strlen(cmd_sp[x]) - start));
		}
		else if (x == i && ((ft_strnstr(cmd_sp[x], ">", 1) || ft_strnstr(cmd_sp[x], "<", 1)) && (int)ft_strlen(cmd_sp[x]) > 1))
		{
			start = find_rm_size((char *)cmd_sp[x] + 1, 0, &lock);
			if (start)
			{
				if (ft_strnstr(cmd_sp[x], ">", 1))
					ret = ft_strjoin_swap(ret, ft_substr(cmd_sp[x], start + 1, (int)ft_strlen(ft_strchr(cmd_sp[x], '>')) - (start - lock)));
				else
					ret = ft_strjoin_swap(ret, ft_substr(cmd_sp[x], start + 1, (int)ft_strlen(ft_strchr(cmd_sp[x], '<')) - (start - lock)));
			}		
		}
		else
		{
			if (x == i && find_rm_size(cmd_sp[x], 0, &lock) != (int)ft_strlen(cmd_sp[x]))
				ret = ft_strjoin_swap(ret, find_middle(cmd_sp[x], 0));
			else
				ret = ft_strjoin_swap(ret, cmd_sp[x]);
		}
		ret = ft_strjoin_swap(ret, " ");
	}
	i = -1;
	x = 0;
	while (ret[++i] != '\0')
		if (ret[i] == ' ')
			x++;
	if (x == i)
		return (NULL);
	return (ret);
}