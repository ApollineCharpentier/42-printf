/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** int_width prints and returns the characters
** to be printed to reach the required width
** int_width checks for zeros or spaces to be printed based on the flag
** len is the length of the int including (-) sign
** if precision > len, zeros are printed to reach precision size
** then ' ' to reach width size
*/

int	int_width(t_flags flags, int len, int nb)
{
	int rtn;

	rtn = 0;
	if (flags.zero)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			rtn = rtn + 1;
		}
		rtn = rtn + ft_width(flags.width - len, '0');
	}
	else if (flags.precision >= len)
	{
		if (nb < 0)
			rtn = rtn + ft_width(flags.width - flags.precision - 1, ' ');
		else
			rtn = rtn + ft_width(flags.width - flags.precision, ' ');
	}
	else
		rtn = rtn + ft_width(flags.width - len, ' ');
	return (rtn);
}

/*
** int_precision prints and returns the number of
** characters required to reach precision size
** if precision > len, 0 are printed
** the (-) sign is outside the precision length
*/

int	int_precision(t_flags flags, int len, int nb)
{
	int i;
	int rtn;

	i = 0;
	rtn = 0;
	if (nb < 0 && flags.precision < len && !flags.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (flags.precision > 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			rtn++;
			i--;
		}
		while (i++ < flags.precision - len)
		{
			write(1, "0", 1);
			rtn++;
		}
	}
	return (rtn);
}

/*
** int_minus prints and returns all characters
** to be printed for width, precision and the int
** int_minus prints the int on the left if the minus flag is activated
** set string without the - sign which
** will be printed in ft_precision or ft_width
*/

int	int_minus(t_flags flags, int len, char *str, int nb)
{
	int rtn;

	rtn = 0;
	if (nb < 0)
		str++;
	if (flags.minus)
	{
		rtn = rtn + int_precision(flags, len, nb);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
		rtn = rtn + int_width(flags, len, nb);
	}
	if (!flags.minus)
	{
		rtn = rtn + int_width(flags, len, nb);
		rtn = rtn + int_precision(flags, len, nb);
		rtn = rtn + ft_putstr_fd_conv(str, 1);
	}
	return (rtn);
}

/*
** int_conv prints and returns all characters
** to be printed for width, precision and the int
** int_conv calls the flags and the int argument converted to a string
** int_conv checks only prints the zero width flag if there is no precision flag
*/

int	type_int(t_flags flags, va_list args)
{
	int		nb;
	char	*str;
	int		len;
	int		rtn;

	rtn = 0;
	nb = va_arg(args, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (flags.zero && (flags.minus || flags.precision >= 0))
		flags.zero = 0;
	if (flags.precision == 0 && *str == '0')
	{
		rtn = rtn + ft_width(flags.width, ' ');
		return (rtn);
	}
	rtn = rtn + int_minus(flags, len, str, nb);
	return (rtn);
}
