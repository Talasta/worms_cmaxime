/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:49:39 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/19 10:44:00 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num(t_adj *adj, va_list ap)
{
	if (adj->percent == 0)
		return (def(adj, ap));
	if (*adj->format == '0')
	{
		adj->fill = '0';
		adj->format++;
	}
	else
	{
		adj->size = ft_atoi(adj->format);
		while (ft_cinstr(*adj->format, "0123456789"))
			adj->format++;
	}
	return (0);
}
