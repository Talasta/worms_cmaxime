/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:12:04 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/14 12:52:59 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_ulist
{
	void			*content;
	size_t			content_size;
	struct s_ulist	*next;
	struct s_ulist	*prev;
}					t_ulist;

typedef struct		s_read
{
	int				fd;
	int				pos;
	char			buff[BUFF_SIZE];
}					t_read;

#endif
