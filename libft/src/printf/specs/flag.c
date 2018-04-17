/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:50:11 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/15 14:31:24 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag(t_adj *adj, va_list ap)
{
	if (adj->percent == 0)
		return (def(adj, ap));
	if (adj->format[0] == 'h' && adj->flag == 'h')
		adj->flag = 'i';
	if (adj->flag == 0)
		adj->flag = adj->format[0];
	adj->format++;
	return (0);
}
