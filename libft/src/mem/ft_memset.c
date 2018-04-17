/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:28:18 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/18 13:43:16 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	**point_b;

	if ((int)len <= 0)
		return (0);
	point_b = (char**)(&b);
	i = 0;
	while (i < len)
	{
		(*point_b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
