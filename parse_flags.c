/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:32:19 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/05 18:43:55 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** init_flags initializes all flags at zero, except for the precision at -1
** because the precision flag can be activated
** and equal to zero (ex - to trunc a string)
*/

t_flags		init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.point = 0;
	flags.advance = 0;
	return (flags);
}

/*
** is_flag returns 1 if a flag is recognized in the string
** is_flags is used in treat_flags, parser_flags and ft_printf
*/

int			is_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

/*
** treat_flags goes across the flags when
** % is found and returns flags successively
** flags.width and flags.precision are converted to
** int, since the arguments are chars
*/

t_flags		treat_flags(char input, t_flags flags, va_list args)
{
	if (input == '-')
		flags.minus = 1;
	else if (input == '0' && flags.width < 1 && !flags.point)
		flags.zero = 1;
	else if (ft_isdigit(input) && !flags.point)
		flags.width = flags.width * 10 + input - '0';
	else if (input == '.')
	{
		flags.point = 1;
		flags.precision = 0;
	}
	else if (ft_isdigit(input) && flags.point)
		flags.precision = flags.precision * 10 + input - '0';
	else if (input == '*')
		flags = treat_stars(flags, args);
	return (flags);
}

/*
** treat_stars returns width, precision and minus flags if applicable
** treat_stars is a sub function of treat_flags
** treat_stars is used when printf has width
** and precision as arguments (with * in arg[0])
*/

t_flags		treat_stars(t_flags flags, va_list args)
{
	if (flags.point)
		flags.precision = va_arg(args, int);
	else if (flags.width < 1)
	{
		flags.width = va_arg(args, int);
		if (flags.width < 0)
		{
			flags.width = -1 * flags.width;
			flags.minus = 1;
		}
	}
	return (flags);
}

/*
** parser_flags returns the flags structure
** parser_flags calls treat_flags when a flag is found in the browsed string
*/

t_flags		parse_flags(const char *input, t_flags flags, va_list args)
{
	int i;

	i = 0;
	while (input[i] && is_flag(input[i]))
	{
		flags = treat_flags(input[i], flags, args);
		i++;
	}
	return (flags);
}
