/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:58:50 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:40:10 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;
	int		l;
	char	*str;

	str = (char*)haystack;
	a = 0;
	b = 0;
	l = 0;
	while (needle[l] != '\0')
		l++;
	if (l == 0)
		return (str);
	while (str[a] != '\0')
	{
		while (needle[b] == str[a + b])
		{
			if (b++ == l - 1)
				return (str + a);
		}
		b = 0;
		a++;
	}
	return (0);
}
