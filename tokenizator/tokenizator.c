/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:10:00 by vifernan          #+#    #+#             */
/*   Updated: 2022/08/02 15:52:01 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*create_node(char *cmd_stg)
{
	t_pipe	*ret;
	char	**aux;


	if (!cmd_stg)
		return (NULL);
	aux = NULL;
	ret = (t_pipe *)malloc(sizeof(t_pipe));
	ft_bzero(ret, sizeof(t_pipe));
	aux = cmd_arg_quottes(cmd_stg);
	ret->in_fd = take_heredoc(&cmd_stg, -1, aux, NULL);
	write(STDERR_FILENO, "AFTER: ", 7);
	write(STDERR_FILENO, cmd_stg, ft_strlen(cmd_stg));
	write(STDERR_FILENO, "\n", 1);
	//take_redirections(ret, cmd_sp);
	//take_args_path(ret_cmd_sp);
	//free(aux);
	//leaks();
	return (ret);
}

t_pipe	*tokenizator(t_data *data, int i)
{
	t_pipe	*ret;
	t_pipe	*new;

	if (!data->spt_pipes)
		return (NULL);
	while (data->spt_pipes[++i] != NULL)
	{
		if (i == 0)
		{
			ret = create_node(data->spt_pipes[i]);
			new = ret;
		}
		else
		{
			new->next = create_node(data->spt_pipes[i]);
			new = new->next;
		}
		write(STDERR_FILENO, "TOK: ", 5);
		write(STDERR_FILENO, "lola\n", 5);
		free(data->spt_pipes[i]);
	}
	free(data->spt_pipes);
	//free(aux);
//	leaks();
	return (ret);
}
