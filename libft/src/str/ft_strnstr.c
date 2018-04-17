/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:09:38 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:42:07 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		a;
	size_t		b;
	size_t		l;
	char		*str;

	str = (char*)haystack;
	a = 0;
	b = 0;
	l = 0;
	while (needle[l] != '\0')
		l++;
	if (l == 0)
		return (str);
	while (str[a] != '\0' && a < len)
	{
		while (needle[b] == str[a + b] && a + b < len)
		{
			if (b == l - 1)
				return (str + a);
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}
