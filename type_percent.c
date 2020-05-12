/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** percent_conv prints the % sign
*/

int	type_percent(t_flags flags)
{
	int rtn;

	rtn = 0;
	if (flags.minus)
	{
		ft_putchar_fd('%', 1);
		if (flags.zero)
			rtn = rtn + ft_width(flags.width - 1, ' ');
		else
			rtn = rtn + ft_width(flags.width - 1, ' ');
	}
	else if (!flags.minus)
	{
		if (flags.zero)
			rtn = rtn + ft_width(flags.width - 1, '0');
		else
			rtn = rtn + ft_width(flags.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (rtn + 1);
}
