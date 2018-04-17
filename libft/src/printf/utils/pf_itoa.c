/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:56:59 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/20 22:23:45 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(uintmax_t n)
{
	int len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*pf_itoa(uintmax_t n)
{
	int				len;
	int				save;
	char			*dst;

	len = nlen(n);
	save = len;
	if (!(dst = (char*)malloc(len + 1)))
		return (NULL);
	while (len)
	{
		dst[--len] = n % 10 + '0';
		n /= 10;
	}
	dst[save] = 0;
	return (dst);
}
