/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:59:54 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/10 10:11:18 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*dst;

	if (!s || !f)
		return ((char*)s);
	i = ft_strlen(s);
	if (!(dst = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		dst[i] = f(dst[i]);
		i++;
	}
	return (dst);
}
