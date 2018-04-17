/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:50:10 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/19 18:49:15 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		point(t_adj *adj, va_list ap)
{
	if (adj->percent == 0)
		return (def(adj, ap));
	adj->format++;
	adj->prec = ft_atoi(adj->format);
	while (ft_cinstr(*adj->format, "0123456789"))
		adj->format++;
	return (0);
}
