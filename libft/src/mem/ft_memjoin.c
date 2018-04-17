/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:48:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/19 14:24:59 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(char *s1, char *s2, size_t l1, size_t l2)
{
	char *dst;

	if (!s1 && !s2)
		return (NULL);
	if (!(dst = ft_memalloc(l1 + l2)))
		return (NULL);
	ft_memcpy(dst, s1, l1);
	ft_memcpy(dst + l1, s2, l2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (dst);
}
