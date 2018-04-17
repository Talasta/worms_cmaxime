/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:12:33 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 14:52:50 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s2) + 1 : ft_strlen(s1) + 1;
	len = len > n ? n : len;
	return (ft_memcmp(s1, s2, len));
}
