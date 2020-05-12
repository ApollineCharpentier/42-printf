/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_char(t_flags flags, va_list args)
{
	if (flags.minus && flags.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_width(flags.width - 1, ' ');
		return (flags.width);
	}
	else if (!flags.minus && flags.width > 1)
		ft_width(flags.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	if (flags.width > 1)
		return (flags.width);
	return (1);
}
