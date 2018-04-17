/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:44:34 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/01 10:33:57 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int	ct(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char	**split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char**)malloc(sizeof(*tab) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(tab[k] = (char*)malloc(sizeof(char) * (ct(s + i, c) + 1))))
				return (NULL);
			j = 0;
			while (s[i] != c && s[i] != '\0')
				tab[k][j++] = s[i++];
			tab[k++][j] = '\0';
		}
	}
	tab[k] = 0;
	return (tab);
}

extern char	**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	else
		return (split(s, c));
}
