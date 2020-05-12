/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexa_width(t_flags flags, int len)
{
	int rtn;

	rtn = 0;
	if (flags.zero && flags.precision < 0 && !flags.minus)
		rtn = rtn + ft_width(flags.width - len, '0');
	else if (flags.precision >= len)
		rtn = rtn + ft_width(flags.width - flags.precision, ' ');
	else
		rtn = rtn + ft_width(flags.width - len, ' ');
	return (rtn);
}

int		hexa_prec(int precision, int len)
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

int		hexa_minus(t_flags flags, int len, char *str)
{
	int rtn;

	rtn = 0;
	if (flags.minus)
	{
		rtn = rtn + hexa_prec(flags.precision, len);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
		rtn = rtn + hexa_width(flags, len);
	}
	if (!flags.minus)
	{
		rtn = rtn + hexa_width(flags, len);
		rtn = rtn + hexa_prec(flags.precision, len);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
	}
	return (rtn);
}

int		type_hexa(t_flags flags, va_list args, char *base)
{
	char			*str;
	int				len;
	int				rtn;
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_itoa_base(nb, base);
	len = ft_strlen(str);
	rtn = 0;
	if (flags.precision == 0 && *str == '0')
	{
		rtn = rtn + ft_width(flags.width, ' ');
		return (rtn);
	}
	rtn = hexa_minus(flags, len, str);
	free(str);
	return (rtn);
}
