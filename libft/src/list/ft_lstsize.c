/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:20:20 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/15 15:42:42 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (!begin_list)
		return (0);
	tmp = begin_list;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
