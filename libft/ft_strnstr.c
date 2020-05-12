/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:15:52 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/17 09:47:48 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i <= size)
	{
		j = 0;
		if (str[i] == needle[j])
			while (str[i + j] == needle[j] && i + j < size)
			{
				if (needle[j + 1] == '\0')
					return ((char*)&str[i]);
				j++;
			}
		i++;
	}
	return (NULL);
}
