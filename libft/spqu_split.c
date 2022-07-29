/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spqu_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:34:06 by vifernan          #+#    #+#             */
/*   Updated: 2022/07/29 17:42:57 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	check_quo(char const *s, char c, int i)
{
	int		j;

	j = i;
	while (s[++j] != '\0')
	{
		if (s[j] == c)
			return (j + 1);
	}
	return (i + 1);
}

static	int skip_quo(char const *s, int i, char c)
{
	char x;

	x = 0;
	if (s[i] == '\"' || s[i] == '\'')
	{
		if (s[i] == '\"')
			x = '\"';
		else
			x = '\'';
		i = check_quo(s, x, i);
	}
	while (s[i] != c && s[i] != '\'' \
		&& s[i] != '\"'  && s[i] != '\0')
		i++;

	return (i);
}

char	**ft_inend(char **dst, char const *init, char c)
{
	int			i;
	int			j;
	int			z;
	char		x;

	i = 0;
	z = 0;
	x = 0;
	while (i < (int)ft_strlen(init))
	{
		if (i == 0 || (init[i - 1] == c && init[i] != c))
			j = i;
		i = skip_quo(init, i, c);
		if ((init[i] == c && init[i + 1] != c) || i == (int)ft_strlen(init))
		{
			if ((i - j) == 0)
				dst[z++] = ft_strdup("\0");
			else
				dst[z++] = ft_substr(init, j, i - j);
		}
		if ((init[i] != '\'' && init[i] != '\"') \
				&& i != (int)ft_strlen(init))
			i++;
		printf("------%p\n", (void *)init);
	}
	dst[z] = NULL;
	return (dst);
}

char	**spqu_split(char const *s, char c)
{
	int			i;
	int			count;
	char		**dst;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		i = skip_quo(s, i, c);
		if (s[i] == c && s[i + 1] != c)
			count++;
		if (s[i] != '\'' && s[i] != '\"')
			i++;
	}
	dst = (char **)malloc((count + 2) * sizeof(char *));
	if (!dst)
	{
		free(dst);
		free((void *)s);
		return (NULL);
	}
	return (ft_inend(dst, s, c));
}
/*
int main()
{
	int		i;
	char	**str;

	//str = st_split("echo hola \"|\" | hola | ls -la$\"|\"", '|');
	str = spqu_split("uno    \" hola celkec\"    dos -\'gola    simple\'     tres\"|\"", ' ');
	i = -1;
	while (str[++i] != NULL)
		printf("%s\n", str[i]);
}*/
