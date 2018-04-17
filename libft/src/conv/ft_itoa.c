/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:56:59 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/10 10:03:00 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	int len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

extern char	*ft_itoa(int n)
{
	int				i;
	int				len;
	unsigned int	nb;
	char			*dst;

	dst = 0;
	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	len = nlen(n);
	if (!(dst = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		dst[0] = '-';
		i = 1;
	}
	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	while (len > i)
	{
		dst[--len] = nb % 10 + '0';
		nb /= 10;
	}
	dst[nlen(n)] = '\0';
	return (dst);
}
