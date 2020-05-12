/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** str_precision returns the number of characters from str that are printed
** length if str precision >= str, precision size if  precision < str
** flag mod = 1 is activated to print
** if mod = 0 we obtain the number of characters printed without printing
*/

int		str_precision(char *str, int len, int precision, int mod)
{
	int i;

	i = 0;
	if (precision > -1 && len <= precision)
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else if (precision > -1 && len > precision)
		while (i < precision)
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	return (i);
}

/*
** str_width returns the number of characters required to reach the width
** str_width prints blanks or zeros in case there is a zero flag
*/

int		str_width(int flag_zero, int width)
{
	int rtn;

	rtn = 0;
	if (flag_zero)
		rtn = rtn + ft_width(width, '0');
	else
		rtn = rtn + ft_width(width, ' ');
	return (rtn);
}

/*
** str_special is a special case with no string in the arguments
** without a precision flag (ie. flag.precision = -1 at initialization)
** and (null) is printed
** with a precision flag, blanks are printed
*/

char	*str_special(char *str, t_flags flags)
{
	if (!str && flags.precision)
		str = ft_strdup("(null)");
	if (!str && !flags.precision)
		str = ft_strdup("");
	return (str);
}

/*
** str_conv combines the previous functions to print a string
** str (va_args(args, char *) is the argument obtained after the flag arguments
** if the minus flag is activated, the string is printed first
**  on the left and the width on the right
** if the width is smaller than the precision, then only str_precision is called
*/

int		type_str(t_flags flags, va_list args)
{
	char	*str;
	int		len;
	int		rtn;
	int		prec;

	rtn = 0;
	str = va_arg(args, char*);
	str = str_special(str, flags);
	len = ft_strlen(str);
	prec = str_precision(str, len, flags.precision, 0);
	if (flags.minus && flags.width > prec)
	{
		rtn = rtn + str_precision(str, len, flags.precision, 1);
		rtn = rtn + str_width(flags.zero, flags.width - prec);
	}
	else if (!flags.minus && flags.width > prec)
	{
		rtn = rtn + str_width(flags.zero, flags.width - prec);
		rtn = rtn + str_precision(str, len, flags.precision, 1);
	}
	else
		rtn = rtn + str_precision(str, len, flags.precision, 1);
	return (rtn);
}
