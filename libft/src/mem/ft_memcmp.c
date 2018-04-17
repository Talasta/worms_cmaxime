/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:18:45 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:58:29 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*new1;
	unsigned char	*new2;

	new1 = (unsigned char*)s1;
	new2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*(new1 + i) == *(new2 + i))
		{
			i++;
		}
		else
			return ((int)(*(new1 + i) - *(new2 + i)));
	}
	return (0);
}
