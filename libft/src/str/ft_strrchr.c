/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:43:54 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:42:32 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i--;
	}
	return (NULL);
}
