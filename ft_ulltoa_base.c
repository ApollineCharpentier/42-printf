/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ullnum_length returns the times n has to be divided by b before reaching zero
** ullnum_length defines the length of
** the output for itoa base (shorter no. for base 16)
*/

static int	ullnum_length(unsigned long long n, int b)
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
** put_ullnbr takes as input the int to convert (n)
** the base (base) and its length (len)
** put_ullnbr returns an int and fills str with the num in the new base
** the function is recursive, so calls itself until len = 0
** --len means that you increment len first
** and then assign the function (avoids segfault)
*/

int			put_ullnbr(unsigned long long n, char *base, char *str, int len)
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
		return (put_ullnbr(n / b, base, str, --len));
	}
}

/*
** ft_ulltoa_base converts a long long int (n)
**  into a str in a defined base (base)
** this function is used for pointer conversion in printf (returns address)
** pointers require unsigned long long int (up to 64 bits)
*/

char		*ft_ulltoa_base(unsigned long long n, char *base)
{
	int		b;
	char	*str;
	int		len;

	b = ft_strlen(base);
	len = ullnum_length(n, b);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	put_ullnbr(n, base, str, len - 1);
	return (str);
}
