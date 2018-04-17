/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:34:02 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/20 22:22:17 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*search(char c, t_bind *bind)
{
	int	i;

	i = 1;
	while (i < 17)
	{
		if (ft_cinstr(c, bind[i].str))
			return (bind[i].f);
		i++;
	}
	return (bind[0].f);
}

void	init_adj(t_adj *adj, char *format)
{
	adj->percent = 0;
	adj->minus = 0;
	adj->htag = 0;
	adj->fill = ' ';
	adj->size = -1;
	adj->prec = -1;
	adj->plus = 0;
	adj->flag = 0;
	(void)format;
}

void	free_adj(t_adj *adj)
{
	ft_strdel(&(adj->res));
	ft_memdel((void**)&adj);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;
	t_adj		*adj;
	int			(*f)();

	va_start(ap, format);
	adj = (t_adj*)ft_memalloc(sizeof(t_adj));
	init_adj(adj, (char*)format);
	adj->format = (char*)format;
	while (*adj->format)
	{
		f = search(*adj->format, g_bind);
		if ((ret = f(adj, ap)) == -1)
		{
			adj->ret = adj->bef;
			ret = -1;
			break ;
		}
		adj->ret += ret;
	}
	write(1, adj->res, adj->ret);
	ret = ret == -1 ? -1 : adj->ret;
	free_adj(adj);
	va_end(ap);
	return (ret);
}
