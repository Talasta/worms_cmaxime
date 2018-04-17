/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:29:42 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/02/13 19:00:13 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dst;

	if (!s || (int)len < 0)
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	ft_strncpy(dst, s + start, len);
	return (dst);
}
