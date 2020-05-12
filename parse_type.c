/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:10:12 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:45:26 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_width returns and prints the required
** characters so as to reach the width size
** ft_width is used in all conv functions (char, str, int...)
*/

int	ft_width(int width, char c)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

/*
** ft_putstr_fd_conv returns and prints in fd the string str
** ft_putstr_fd_conv differs from the lib ft_pustr_fd
** which prints str and returns a void
*/

int	ft_putstr_fd_conv(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

/*
** parser_conv returns the number of characters printed and prints the argument
** parser_conv checks the type of the argument
** to be printed and calls the function accordingly
*/

int	parse_type(char input, t_flags flags, va_list args)
{
	int rtn;

	rtn = 0;
	if (input == 'd' || input == 'i')
		rtn = type_int(flags, args);
	else if (input == 'c')
		rtn = type_char(flags, args);
	else if (input == 's')
		rtn = type_str(flags, args);
	else if (input == 'x')
		rtn = type_hexa(flags, args, "0123456789abcdef");
	else if (input == 'X')
		rtn = type_hexa(flags, args, "0123456789ABCDEF");
	else if (input == 'p')
		rtn = type_pointer(flags, args);
	else if (input == 'u')
		rtn = type_unsigned(flags, args);
	else if (input == '%')
		rtn = type_percent(flags);
	return (rtn);
}
