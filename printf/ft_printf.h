/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:06:07 by ialvarez          #+#    #+#             */
/*   Updated: 2022/08/04 17:42:22 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minishell.h"

# define SPECIFIERS "cspdiuxX%"

typedef struct s_flags{
	int		o;
	char	*str;
	char	*some;
	int		ret;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_vsprintf(const char *format, va_list a_list, t_flags *flags);
char	*ft_char2str(char chr);
char	*ft_simple(const char *format, va_list a_list, t_flags *fl);

#endif
