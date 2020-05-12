/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:43:38 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/13 11:35:53 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*tmp;

	i = 0;
	tmp = str;
	while (i < n)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
