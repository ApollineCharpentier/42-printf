/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_pointer(char *str, int i, int mod)
{
	if (mod)
		write(1, &str[i], 1);
	return (1);
}

int		pointer_precision(char *str, int len, int precision, int mod)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (precision > -1 && len <= precision)
		while (str[i])
		{
			if (mod)
			{
				while (len++ < precision)
					j += ft_putstr_fd("0", 1);
				write(1, &str[i], 1);
			}
			i++;
		}
	else if (precision > -1 && len > precision)
		while (i - 1 < precision)
			i = i + print_pointer(str, i, mod);
	else
		while (str[i])
			i = i + print_pointer(str, i, mod);
	return (i + j);
}

int		pointer_minus(t_flags flags, int len, char *str)
{
	int rtn;

	rtn = 0;
	if (flags.minus)
	{
		rtn = rtn + ft_putstr_fd_conv("0x", 1);
		rtn = rtn + pointer_precision(str, len, flags.precision, 1);
		rtn = rtn + ft_width(flags.width - (len + 2), ' ');
	}
	else if (!flags.minus)
	{
		rtn = rtn + ft_width(flags.width - (len + 2), ' ');
		rtn = rtn + ft_putstr_fd_conv("0x", 1);
		rtn = rtn + pointer_precision(str, len, flags.precision, 1);
	}
	return (rtn);
}

char	*is_str(t_flags flags, unsigned long long n)
{
	char *str;

	if (!n && !flags.precision)
		str = ft_strdup("");
	else if (!n && flags.precision)
		str = ft_strdup("0");
	else
		str = ft_ulltoa_base(n, "0123456789abcdef");
	return (str);
}

int		type_pointer(t_flags flags, va_list args)
{
	char				*str;
	int					len;
	int					rtn;
	unsigned long long	n;

	n = va_arg(args, unsigned long long);
	str = is_str(flags, n);
	rtn = 0;
	len = ft_strlen(str);
	rtn = rtn + pointer_minus(flags, len, str);
	free(str);
	return (rtn);
}
