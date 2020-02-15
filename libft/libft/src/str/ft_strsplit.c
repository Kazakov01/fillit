/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:14:44 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 13:58:35 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*through(char **str, char c, int i)
{
	char *m;

	m = NULL;
	while (**str)
	{
		if (i == 0 && **str != c)
		{
			m = *str;
			break ;
		}
		if (**str != c && *(*str - 1) == c && i - 1 >= 0)
		{
			m = *str;
			break ;
		}
		*str = *str + 1;
		i++;
	}
	if (*(*str + 1) != '\0')
		*str = *str + 1;
	return (m);
}

static char		*getwrd(char *m, size_t size)
{
	char *tmp;

	tmp = ft_strdup(m);
	m = ft_strnew(size);
	m = ft_strncpy(m, tmp, size);
	free(tmp);
	tmp = NULL;
	return (m);
}

static size_t	cutwrd(char *m, char c)
{
	size_t size;

	size = 0;
	while (m[size] != '\0' && m[size] != c)
		size++;
	return (size);
}

static int		wrdnb(char const *s, char c)
{
	int nbm;
	int i;

	nbm = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			nbm++;
		if (s[i] != c && (i > 0 && s[i - 1] == c))
			nbm++;
		i++;
	}
	return (nbm);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		nbm;
	char	*str_s;
	int		i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	i = 0;
	str_s = (char *)s;
	nbm = wrdnb(s, c);
	if (!(split = (char **)ft_memalloc(sizeof(*split) * (nbm + 1))))
		return (NULL);
	while (i < nbm)
	{
		split[i] = through(&str_s, c, i);
		size = cutwrd(split[i], c);
		split[i] = getwrd(split[i], size);
		i++;
	}
	split[i] = NULL;
	return (split);
}
