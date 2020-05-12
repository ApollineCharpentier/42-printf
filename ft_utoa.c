/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:55:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:49:30 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** uinum_length returns the length of n + 1 for /0
** static int is required to use i in ft_utoa
*/

static int		uinum_length(long n)
{
	int i;

	i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** fill_string fills the malloced string (str) of length (len)
**it returns n as a string
*/

static char		*fill_string(char *str, int len, long n)
{
	str[--len] = '\0';
	while (n / 10 >= 1)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	str[0] = (n % 10) + '0';
	return (str);
}

/*
** ft_utoa converts an unsigned int (n) into a string
** if n < 0, the nbr = 2^32 - n
*/

char			*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = uinum_length(nbr);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	str = fill_string(str, len, nbr);
	return (str);
}
