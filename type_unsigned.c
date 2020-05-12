/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unisgned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_width(t_flags flags, int len)
{
	int rtn;

	rtn = 0;
	if (flags.zero && !flags.minus && flags.precision < 0)
		rtn = rtn + ft_width(flags.width - len, '0');
	else if (flags.precision >= len)
		rtn = rtn + ft_width(flags.width - flags.precision, ' ');
	else
		rtn = rtn + ft_width(flags.width - len, ' ');
	return (rtn);
}

int		unsigned_prec(int precision, int len)
{
	int i;

	i = 0;
	if (precision)
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

int		unsigned_minus(t_flags flags, int len, char *str)
{
	int rtn;

	rtn = 0;
	if (flags.minus)
	{
		rtn = rtn + unsigned_prec(flags.precision, len);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
		rtn = rtn + unsigned_width(flags, len);
	}
	else if (!flags.minus)
	{
		rtn = rtn + unsigned_width(flags, len);
		rtn = rtn + unsigned_prec(flags.precision, len);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
	}
	return (rtn);
}

/*
** unsigned_conv returns the number of characters
** and prints a string for and unsigned int n
** if n < 0, it prints 2^32 - n
*/

int		type_unsigned(t_flags flags, va_list args)
{
	char	*str;
	int		len;
	int		rtn;

	str = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	rtn = 0;
	if (flags.precision == 0 && *str == '0')
	{
		rtn = rtn + ft_width(flags.width, ' ');
		return (rtn);
	}
	rtn = rtn + unsigned_minus(flags, len, str);
	return (rtn);
}
