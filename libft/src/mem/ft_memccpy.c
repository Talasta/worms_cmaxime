/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:01:32 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:58:50 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char*)src;
	while (i < n)
	{
		if (*(new + i) == (unsigned char)c)
		{
			*((unsigned char*)dst + i) = *(new + i);
			return ((unsigned char*)dst + i + 1);
		}
		else
			*((unsigned char*)dst + i) = *(new + i);
		i++;
	}
	return (NULL);
}
