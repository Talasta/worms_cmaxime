/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:06:36 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/01/08 17:07:24 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	convert(t_adj *adj, va_list ap)
{
	uintmax_t	val;

	if (*adj->format == 'C')
		adj->flag = 'l';
	if (adj->flag == 'l')
		val = (wchar_t)va_arg(ap, wchar_t);
	else
		val = (char)va_arg(ap, int);
	return (val);
}

intmax_t			max_wchar(void)
{
	if (MB_CUR_MAX == 1)
		return (255);
	if (MB_CUR_MAX == 2)
		return (0x7ff);
	if (MB_CUR_MAX == 3)
		return (0xffff);
	if (MB_CUR_MAX == 4)
		return (0x10ffff);
	return (0);
}

static void			size_wchar(wchar_t wchar, int *csize)
{
	if (wchar <= 127)
		*csize = 1;
	else if (wchar <= 2047 && MB_CUR_MAX > 1)
		*csize = 2;
	else if (wchar <= 0xffff && MB_CUR_MAX > 2)
		*csize = 3;
	else if (wchar <= 0x10ffff && MB_CUR_MAX > 3)
		*csize = 4;
}

char				*wchar_to_char(wchar_t wchar, int *csize)
{
	char	*res;

	size_wchar(wchar, csize);
	res = (char*)ft_memalloc(*csize);
	if (*csize == 1)
		res[0] = wchar;
	else if (*csize == 2)
	{
		res[0] = (wchar >> 6) + 0xC0;
		res[1] = (wchar & 0x3f) + 0x80;
	}
	else if (*csize == 3)
	{
		res[0] = (wchar >> 12) + 0xE0;
		res[1] = ((wchar >> 6) & 0x3F) + 0x80;
		res[2] = (wchar & 0x3F) + 0x80;
	}
	else if (*csize == 4)
	{
		res[0] = (wchar >> 18) + 0xF0;
		res[1] = ((wchar >> 12) & 0x3F) + 0x80;
		res[2] = ((wchar >> 6) & 0x3F) + 0x80;
		res[3] = (wchar & 0x3F) + 0x80;
	}
	return (res);
}

int					c(t_adj *adj, va_list ap)
{
	uintmax_t	val;
	char		*res;
	int			ret;
	char		*fill;
	int			csize;

	if (adj->percent == 0)
		return (def(adj, ap));
	if (((intmax_t)(val = convert(adj, ap))) > max_wchar() || (adj->flag == 'l'\
		&& (intmax_t)val < 0) || (val >= 0xd800 && val <= 0xdfff))
		return (-1);
	ret = adj->ret;
	res = wchar_to_char(val, &csize);
	adj->size = adj->size < csize ? csize : adj->size;
	fill = ft_memalloc(adj->size);
	ft_memset(fill, adj->fill, adj->size - csize);
	if (adj->minus == 0)
		adj->res = ft_memjoin(adj->res, fill, ret, adj->size - csize);
	ret += adj->minus == 0 ? adj->size - csize : 0;
	adj->res = ft_memjoin(adj->res, res, ret, csize);
	if (adj->minus == 1)
		adj->res = ft_memjoin(adj->res, fill, ret + csize, adj->size - csize);
	ret = adj->size;
	init_adj(adj, adj->format++);
	return (ret);
}
