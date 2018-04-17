/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:22:23 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/10 10:11:15 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	if (!s || !f)
		return ((char *)s);
	i = ft_strlen(s);
	if (!(dst = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		dst[i] = f((unsigned int)i, dst[i]);
		i++;
	}
	return (dst);
}
