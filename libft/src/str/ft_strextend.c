/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:24:15 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/01/14 15:21:46 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strextend(char *s1, char *s2)
{
	char *dst;

	dst = 0;
	if (!s2)
		return (s1);
	if (!s1)
	{
		if (s2)
		{
			dst = ft_strdup(s2);
			ft_strdel(&s2);
		}
		return (dst);
	}
	if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (dst);
}
