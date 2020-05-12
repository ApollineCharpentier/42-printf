/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** num_length returns times n has to be divided by b before reaching zero
** num_length defines the length output by itoa base (shorter if base is 16)
*/

static int		num_length(unsigned int n, int b)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / b;
		i++;
	}
	return (i);
}

/*
** put_nbr takes as input the int to convert (n)
** the base (base) and its length (len)
** put_nbr returns an int and fills str with the num in base 16
** the function is recursive, so calls itself until len = 0
** --len means that you increment len first
** and then assign the function (avoids segfault)
*/

int				put_nbr(unsigned int n, char *base, char *str, int len)
{
	int b;

	b = ft_strlen(base);
	if (len == 0)
	{
		str[len] = base[n % b];
		return (0);
	}
	else
	{
		str[len] = base[n % b];
		return (put_nbr(n / b, base, str, --len));
	}
}

/*
** ft_itoa_base converts an int (nb) into a str in a defined base (base)
** for hexadecimals the base is "0123456789abcdef" - size 16
*/

char			*ft_itoa_base(unsigned int nbr, char *base)
{
	int		b;
	char	*str;
	int		len;

	b = ft_strlen(base);
	len = num_length(nbr, b);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	put_nbr(nbr, base, str, len - 1);
	return (str);
}
