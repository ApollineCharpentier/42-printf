/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <apcharpe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:23:02 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:59:47 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_chars prints the text which are not flags
*/

int		print_chars(char c)
{
	int rtn;

	rtn = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		rtn++;
	}
	return (rtn);
}

/*
** ft_printf copies the print function and returns the number of chars printed
** ft_printf includes flags (* - . precision and width)
** ft_printf includes types (int, char, str, )
** it takes the arguments after the string as flags and type
*/

int		ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;
	int		rtn;
	int		i;

	rtn = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		rtn = rtn + print_chars(input[i]);
		if (input[i] == '%' && input[i + 1] != '\0')
		{
			i = i + 1;
			flags = init_flags(flags);
			flags = parse_flags(&input[i], flags, args);
			while (is_flag(input[i]))
				i++;
			if (!input[i])
				return (0);
			rtn = rtn + parse_type(input[i], flags, args);
		}
		i++;
	}
	return (rtn);
}
