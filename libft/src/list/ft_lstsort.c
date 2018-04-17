/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:00:31 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/01/11 12:17:02 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_list_sort(t_list *lst, int (*cmp)())
{
	void		*tmp;
	t_list		*curr;

	curr = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->content, lst->next->content)) == 0)
		{
			tmp = lst->content;
			lst->content = lst->next->content;
			lst->next->content = tmp;
			lst = curr;
		}
		else
			lst = lst->next;
	}
	lst = curr;
	return (lst);
}

void			ft_listsort(t_list **lst, int (*cmp)())
{
	*lst = ft_list_sort(*lst, cmp);
}
