/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:34:58 by blefeuvr          #+#    #+#             */
/*   Updated: 2017/12/20 19:42:52 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_adj
{
	char		*format;
	char		*res;
	int			bef;
	int			ret;
	int			percent;
	int			plus;
	int			minus;
	int			space;
	int			htag;
	char		fill;
	int			size;
	int			prec;
	char		flag;
}				t_adj;

typedef struct	s_bind
{
	char		*str;
	int			(*f)(t_adj *adj, va_list ap);
}				t_bind;

int				ft_printf(const char *restrict format, ...);
void			init_adj(t_adj *adj, char *format);
int				def(t_adj *adj, va_list ap);
int				percent(t_adj *adj, va_list ap);
int				minus(t_adj *adj, va_list ap);
int				plus(t_adj *adj, va_list ap);
int				htag(t_adj *adj, va_list ap);
int				num(t_adj *adj, va_list ap);
int				point(t_adj *adj, va_list ap);
int				space(t_adj *adj, va_list ap);
int				flag(t_adj *adj, va_list ap);
int				d(t_adj *adj, va_list ap);
int				def(t_adj *adj, va_list ap);
int				u(t_adj *adj, va_list ap);
int				o(t_adj *adj, va_list ap);
int				x(t_adj *adj, va_list ap);
int				p(t_adj *adj, va_list ap);
int				c(t_adj *adj, va_list ap);
int				s(t_adj *adj, va_list ap);
char			*pf_itoa(intmax_t n);
char			*pf_itoa_base(intmax_t n, char *base);
char			*wchar_to_char(wchar_t wchar, int *csize);
intmax_t		max_wchar(void);

static t_bind	g_bind[] =
{
	{"", def},
	{"%", percent},
	{"+", plus},
	{"-", minus},
	{" ", space},
	{"#", htag},
	{".", point},
	{"0123456789", num},
	{"hljz", flag},
	{"diD", d},
	{"uU", u},
	{"oO", o},
	{"xX", x},
	{"cC", c},
	{"sS", s},
	{"p", p}
};

#endif
