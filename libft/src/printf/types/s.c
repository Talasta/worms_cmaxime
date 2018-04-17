/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:11:25 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/21 10:38:33 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*convert(t_adj *adj, va_list ap)
{
	wchar_t	*val;

	if (adj->minus == 1)
		adj->fill = ' ';
	if (*adj->format == 'S')
		adj->flag = 'l';
	if (adj->flag == 'l')
		val = (wchar_t*)va_arg(ap, wchar_t*);
	else
		val = va_arg(ap, void*);
	return (val);
}

static char	*wchar_to_str(wchar_t *wchar, int *ssize, t_adj *adj)
{
	int			csize;
	char		*res;
	char		*str;

	res = 0;
	*ssize = 0;
	csize = 0;
	str = 0;
	while (*wchar != '\0')
	{
		str = wchar_to_char(*wchar, &csize);
		if (*ssize + csize > adj->prec && adj->prec != -1)
			break ;
		if ((intmax_t)(*wchar) > max_wchar() || \
				(*wchar >= 0xd800 && *wchar <= 0xdfff))
		{
			ft_strdel(&str);
			*ssize = -1;
			break ;
		}
		res = ft_memjoin(res, str, *ssize, csize);
		*ssize += csize;
		wchar++;
	}
	return (res);
}

static int	s_cont(t_adj *adj, char *res, int ret, int ssize)
{
	char		*fill;
	int			size;

	size = ssize > adj->prec && adj->prec != -1 ? adj->prec : ssize;
	fill = ft_memalloc(adj->size - size);
	ft_memset(fill, adj->fill, adj->size - size);
	if (adj->minus == 0 && adj->size > size)
	{
		adj->res = ft_memjoin(adj->res, fill, ret, adj->size - size);
		ret += adj->size - size;
	}
	adj->res = ft_memjoin(adj->res, res, ret, size);
	ret += size;
	if (adj->minus == 1 && adj->size > size)
	{
		adj->res = ft_memjoin(adj->res, fill, ret, adj->size - size);
		ret += adj->size - size;
	}
	adj->format++;
	init_adj(adj, adj->format);
	adj->bef = ret;
	return (ret - adj->ret);
}

int			s(t_adj *adj, va_list ap)
{
	void		*val;
	char		*res;
	int			ret;
	int			ssize;

	ssize = 0;
	if (adj->percent == 0)
		return (def(adj, ap));
	val = convert(adj, ap);
	if (adj->flag && adj->flag != 'l' && val)
		return (-1);
	ret = adj->ret;
	if (val == 0 || adj->flag != 'l')
	{
		res = ft_strdup(val != 0 ? val : "(null)");
		ssize = ft_strlen(res);
	}
	else
		res = wchar_to_str(val, &ssize, adj);
	if (ssize == -1)
	{
		ft_memdel((void**)&res);
		return (-1);
	}
	return (s_cont(adj, res, ret, ssize));
}
