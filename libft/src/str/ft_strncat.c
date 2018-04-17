/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:31:12 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 11:27:34 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i_dest;
	size_t i_src;

	i_dest = 0;
	i_src = 0;
	while (s1[i_dest] != '\0')
		i_dest++;
	while (s2[i_src] != '\0' && i_src < n)
	{
		s1[i_dest] = s2[i_src];
		i_dest++;
		i_src++;
	}
	s1[i_dest] = '\0';
	return (s1);
}
