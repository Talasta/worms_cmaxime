/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:05:42 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/21 16:59:31 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *ptr, size_t size)
{
	void	*dst;

	if (!(dst = (void*)malloc(size)))
		return (NULL);
	ft_bzero(dst, size);
	ft_memccpy(dst, ptr, 0, size);
	ft_memdel(&ptr);
	return (dst);
}
