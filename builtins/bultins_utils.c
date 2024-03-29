/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentum <talentum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:23:56 by vifernan          #+#    #+#             */
/*   Updated: 2023/03/05 20:58:53 by talentum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_var(t_data *data, char *dir, char *key)
{
	int	i;

	i = -1;
	while (data->env[++i] != NULL)
	{
		if (!ft_strcmp(key, data->env[i]))
		{
			free(data->env[i]);
			data->env[i] = dir;
			break ;
		}
	}
}

void	env_update(t_data *data, char *new_line, char *key)
{
	int		i;
	int		j;
	char	**new_env;

	i = -1;
	j = 0;
	while (data->env[++i] != NULL)
	{
		if (ft_strcmp(key, data->env[i]))
			j++;
	}
	new_env = (char **)malloc((j + 2) * sizeof(char *));
	i = -1;
	j = 0;
	while (data->env[++i] != NULL)
	{
		if (ft_strcmp(key, data->env[i]))
			new_env[j++] = ft_strdup(data->env[i]);
		free(data->env[i]);
	}
	new_env[j] = new_line;
	new_env[j + 1] = NULL;
	free(data->env);
	data->env = new_env;
}

char	*search_variable(char **env, char *key)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
	{
		if (!ft_strcmp(key, env[i]))
			return (env[i] + ft_strlen(key));
	}
	return (NULL);
}
