/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:50:03 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/19 18:51:28 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memclen(void *tab, char c)
{
	size_t			l;
	unsigned char	*tmp;

	tmp = (unsigned char*)tab;
	if (!tab)
		return (0);
	l = 0;
	while (tmp[l] != (unsigned char)c)
		l++;
	return (l);
}
