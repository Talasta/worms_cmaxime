/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:10:44 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:59:07 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*dst;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
		{
			dst = (void*)s + i;
			return (dst);
		}
		i++;
	}
	return (NULL);
}
