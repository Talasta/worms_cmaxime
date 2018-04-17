/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:56:28 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/20 22:23:11 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*fill(int side, char c, int l, char *str)
{
	char	*f;
	int		i;

	i = 0;
	f = 0;
	f = (char*)ft_memalloc((l + 1) * sizeof(char));
	while (i < l)
		f[i++] = (side == 0 ? c : ' ');
	if (l > 0)
		f[i] = '\0';
	if (side == 1)
		str = ft_strextend(str, f);
	else
		str = ft_strextend(f, str);
	return (str);
}

int				percent(t_adj *adj, va_list ap)
{
	char	*res;
	int		ret;

	(void)ap;
	ret = 0;
	if (adj->percent == 1)
	{
		res = ft_memalloc(2);
		res[0] = '%';
		res = fill(adj->minus == 0 ? 0 : 1, adj->fill, adj->size - 1, res);
		adj->res = ft_memjoin(adj->res, res, adj->ret, ft_strlen(res));
		init_adj(adj, adj->format);
		ret = ft_strlen(res);
	}
	else
		adj->percent = 1;
	adj->format++;
	return (ret);
}
