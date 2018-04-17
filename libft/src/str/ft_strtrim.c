/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:37:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/10 10:26:07 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (start <= end && ft_isspace(s[start]))
		start++;
	while (end > 0 && ft_isspace(s[end - 1]))
		end--;
	if (start >= end)
		dst = ft_strnew(1);
	else
		dst = ft_strsub(s, (unsigned int)start, (size_t)end - start);
	return (dst);
}
