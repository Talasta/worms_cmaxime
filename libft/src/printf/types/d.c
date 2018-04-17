/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:21:53 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/20 22:24:19 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	convert(t_adj *adj, va_list ap)
{
	uintmax_t	val;

	if (adj->size > adj->prec && adj->prec != -1)
		adj->fill = ' ';
	if (adj->prec == -1)
		adj->prec = 1;
	if (adj->size == -1)
		adj->size = 1;
	if (*adj->format == 'D')
		adj->flag = 'l';
	if (adj->flag == 'h')
		val = (short int)va_arg(ap, int);
	else if (adj->flag == 'l')
		val = (long int)va_arg(ap, long int);
	else if (adj->flag == 'j')
		val = (uintmax_t)va_arg(ap, uintmax_t);
	else if (adj->flag == 'z')
		val = (size_t)va_arg(ap, size_t);
	else if (adj->flag == 'i')
		val = (char)va_arg(ap, int);
	else
		val = va_arg(ap, int);
	return (val);
}

static char			*fill(int side, char c, int l, char *str)
{
	char	*f;
	int		i;

	i = 0;
	if (l <= 0)
		return (str);
	f = (char*)ft_memalloc((l + 1) * sizeof(char));
	while (i < l)
	{
		f[i++] = c;
	}
	if (side == 1)
		str = ft_strextend(str, f);
	else
	{
		if ((str[0] == '-' || str[0] == ' ' || str[0] == '+') && c == '0')
		{
			f[0] = str[0];
			str[0] = c;
		}
		str = ft_strextend(f, str);
	}
	return (str);
}

static char			*add_sign(char c, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	tmp = str;
	str = ft_strjoin(" ", str);
	free(tmp);
	str[i] = c;
	return (str);
}

int					d(t_adj *adj, va_list ap)
{
	uintmax_t	val;
	char		*res;
	int			sign;

	if (adj->percent == 0)
		return (def(adj, ap));
	val = convert(adj, ap);
	sign = (intmax_t)val >= 0 ? 1 : -1;
	(adj->prec != 0 || val != 0) ? (res = pf_itoa(val * sign)) :
		(res = ft_memalloc(1));
	res = fill(0, '0', adj->prec - ft_strlen(res), res);
	if (sign < 1)
		res = add_sign('-', res);
	else if (adj->plus == 1)
		res = add_sign('+', res);
	else if (adj->space == 1)
		res = add_sign(' ', res);
	if (adj->minus == 1)
		res = fill(1, ' ', adj->size - ft_strlen(res), res);
	else if (res[0] || (val == 0 && adj->size > 1))
		res = fill(0, adj->fill, adj->size - ft_strlen(res), res);
	adj->res = ft_memjoin(adj->res, res, adj->ret, ft_strlen(res));
	init_adj(adj, adj->format++);
	adj->bef = adj->ret + ft_strlen(res);
	return (ft_strlen(res));
}
