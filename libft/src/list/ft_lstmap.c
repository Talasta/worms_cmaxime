/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:36:53 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/11/09 16:20:55 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *dst;
	t_list *curr;
	t_list *tmp;
	t_list *new;

	curr = lst;
	while (curr)
	{
		tmp = f(curr);
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		ft_lstadd(&dst, new);
		curr = curr->next;
	}
	return (dst);
}
