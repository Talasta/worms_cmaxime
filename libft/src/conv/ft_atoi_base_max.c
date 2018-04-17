/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:32:26 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/05 18:35:26 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (i < (int)ft_strlen(str))
		return (i);
	else
		return (-1);
}

intmax_t	ft_atoi_base_max(const char *str, int base)
{
	int					i;
	intmax_t			result;
	intmax_t			sign;
	const unsigned char	*s;
	char				*conversion;

	i = 0;
	result = 0;
	conversion = ft_strdup("0123456789abcdef");
	s = (unsigned char *)str;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r' || s[i] == '0')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_strcchr(conversion, s[i]) >= 0
			&& ft_strcchr(conversion, s[i]) < 16)
	{
		result = ft_strcchr(conversion, s[i]) + (result * base);
		i++;
	}
	free(conversion);
	return (result * sign);
}
