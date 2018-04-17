/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:00:28 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/21 10:18:56 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	notdef(t_adj *adj, char c)
{
	char		*res;
	int			ret;
	char		*fill;

	ret = adj->ret;
	res = ft_memalloc(2);
	res[0] = c;
	fill = ft_memalloc(adj->size);
	ft_memset(fill, adj->fill, adj->size - 1);
	if (adj->minus == 0 && adj->size > 0)
	{
		adj->res = ft_memjoin(adj->res, fill, ret, adj->size - 1);
		ret += adj->size - 1;
	}
	adj->res = ft_memjoin(adj->res, res, ret, 1);
	if (adj->minus == 1 && adj->size > 0)
		adj->res = ft_memjoin(adj->res, fill, ret + 1, adj->size - 1);
	adj->format++;
	ret = adj->size == -1 ? 1 : adj->size;
	init_adj(adj, adj->format);
	return (ret);
}

int			def(t_adj *adj, va_list ap)
{
	int		i;
	char	*buf;

	(void)ap;
	if (adj->percent)
		return (notdef(adj, *adj->format));
	i = 0;
	while (adj->format[i] && adj->format[i] != '%')
		i++;
	buf = ft_strsub(adj->format, 0, i);
	adj->res = ft_memjoin(adj->res, buf, adj->ret, ft_strlen(buf));
	adj->format += i;
	init_adj(adj, adj->format);
	adj->bef = adj->ret;
	return (i);
}
