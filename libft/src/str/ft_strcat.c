/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:55:34 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/08 18:50:51 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i_dest;
	int i_src;

	i_dest = 0;
	i_src = 0;
	while (s1[i_dest] != '\0')
		i_dest++;
	while (s2[i_src] != '\0')
	{
		s1[i_dest] = s2[i_src];
		i_dest++;
		i_src++;
	}
	s1[i_dest] = '\0';
	return (s1);
}
