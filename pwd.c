/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:27:00 by ialvarez          #+#    #+#             */
/*   Updated: 2022/06/14 19:58:40 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwdcurrent()
{
	char	buff[FILENAME_MAX];
	char	*current;

	getcwd(buff, FILENAME_MAX);
	current = ft_strdup(buff);
	return (current);
}
/*
int main(void)
{
	ft_putstr_fd(pwdcurrent(), 1);
	return (0);
}
*/
//mirar el error si el getcwd recoge un path que este vacio
