/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:36:15 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/02/14 12:19:47 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*c;
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	if (!(c = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && i < n)
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = 0;
	return (c);
}
