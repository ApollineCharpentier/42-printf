/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:45:22 by apcharpe          #+#    #+#             */
/*   Updated: 2020/03/06 18:46:59 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** stdio - printf, starg - va_arg, stdlib - malloc
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct	s_flags
{
	int minus;
	int zero;
	int point;
	int width;
	int precision;
	int advance;
}				t_flags;

/*
** parse_flags.c
*/
t_flags			init_flags(t_flags flags);
int				is_flag(char c);
t_flags			treat_stars(t_flags flags, va_list args);
t_flags			treat_flags(char input, t_flags flags, va_list args);
t_flags			parse_flags(const char *input, t_flags flags, va_list args);

/*
** parse_type.c
*/
int				ft_width(int width, char c);
int				ft_putstr_fd_conv(char *str, int fd);
int				parse_type(char input, t_flags flags, va_list args);

/*
** ft_itoa_base.c - for type_hexa (ft_itoa for int_conv)
*/
char			*ft_itoa_base(unsigned int nbr, char *base);

/*
** ft_ulltoa_base.c - for type_pointer
** (pointer needs unsigned long long in base 16)
*/
char			*ft_ulltoa_base(unsigned long long n, char *base);

/*
** ft_utoa.c - for type_unsigned (unsigned int)
*/
char			*ft_utoa(unsigned int n);

/*
** type_int.c
*/
int				int_width(t_flags flags, int len, int nb);
int				int_precision(t_flags flags, int len, int nb);
int				int_minus(t_flags flags, int len, char *str, int nb);
int				type_int(t_flags flags, va_list args);

/*
** type_char.c
*/
int				type_char(t_flags flags, va_list args);

/*
** type_str.c
*/
int				str_precision(char *str, int len, int precision, int mod);
int				str_width(int flags_zero, int width);
char			*str_special(char *str, t_flags flags);
int				type_str(t_flags flags, va_list args);

/*
** type_hexa.c
*/
int				hexa_width(t_flags flags, int len);
int				hexa_prec(int precision, int len);
int				hexa_minus(t_flags flags, int len, char *str);
int				type_hexa(t_flags flags, va_list args, char *base);

/*
** type_pointer.c
*/
int				print_pointer(char *str, int len, int mod);
int				pos_precision(char *str, int len, int precision, int mod);
int				pos_minus(t_flags flags, int len, char *str);
char			*is_str(t_flags flags, unsigned long long n);
int				type_pointer(t_flags flags, va_list args);

/*
** type_unsigned.c
*/
int				unsigned_width(t_flags flags, int len);
int				unsigned_prec(int precision, int len);
int				unsigned_minus(t_flags flags, int len, char *str);
int				type_unsigned(t_flags flags, va_list args);

/*
** type_percent.c
*/
int				type_percent(t_flags flags);

/*
** ft_printf.c
*/
int				print_chars(char c);
int				ft_printf(const char *input, ...);

#endif
