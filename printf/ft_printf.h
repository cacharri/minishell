/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:06:07 by ialvarez          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/03 16:12:37 by vifernan         ###   ########.fr       */
=======
/*   Updated: 2022/08/03 17:57:57 by vifernan         ###   ########.fr       */
>>>>>>> vifernan
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
