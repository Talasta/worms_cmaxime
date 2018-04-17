/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 08:44:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/24 11:04:31 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strccpy(char *dst, char *src, char c)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char*)src;
	while (src[i])
	{
		if (*(new + i) == (unsigned char)c)
		{
			*((unsigned char*)dst + i) = '\0';
			return (i);
		}
		else
			*((unsigned char*)dst + i) = *(new + i);
		i++;
	}
	return (-1);
}
