/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:57:09 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/14 16:01:40 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischar(char c, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	start_number(const char *s1, const char *set)
{
	int i;

	i = 0;
	while (ft_ischar(s1[i], set))
		i++;
	return (i);
}

static int	end_number(const char *s1, const char *set)
{
	int i;

	i = ft_strlen(s1) - 1;
	while (ft_ischar(s1[i], set) && i > 0)
		i--;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		str_len;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str_len = end_number(s1, set) - start_number(s1, set) + 1;
	if (str_len < 0)
		str_len = 0;
	if (!(str = malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	str[str_len] = '\0';
	i = end_number(s1, set);
	while (str_len > 0)
	{
		str[str_len - 1] = s1[i];
		i--;
		str_len--;
	}
	return (str);
}
