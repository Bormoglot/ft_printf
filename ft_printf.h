/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:08:17 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/21 17:47:00 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** External headers
*/

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

/*
** Structure definition
**
** charcount: length of string, the return value of ft_printf
** *format: pointer to the format string
** ap: pointer to the argument in a variable argument list
**
** Flag characters: #, 0, -, ' ', +
** min_width
** is_precision: was there a radix point?
** precision
** length_mod: 1 for hh, 2 for h, 3 for l, 4 for ll, 5 for L
** conv_spec: conversion specifier (c, s, p, d, i, o, u, x, X, f)
*/

typedef enum		e_lenmods
{
	HH = 1,
	H = 2,
	EL = 3,
	ELEL = 4,
	L = 5
}					t_lenmods;

typedef struct		s_printf
{
	int			charcount;
	char		*format;
	va_list		ap;
	bool		hash;
	bool		zero;
	bool		minus;
	bool		space;
	bool		plus;
	int			min_width;
	bool		is_precision;
	int			precision;
	t_lenmods	length_mod;
	char		conv_spec;
}					t_printf;

int					ft_printf(char *format, ...);

/*
** Parser functions
*/

void				parse_conv_spec(t_printf *storage);
void				parse_length_mod(t_printf *storage);
void				parse_precision(t_printf *storage);
void				parse_min_width(t_printf *storage);
void				parse_flags(t_printf *storage);

/*
**	Converters functions
*/

int     track_converters(t_printf *storage);

int		convert_int(t_printf *storage);
int		convert_unsigned_int(t_printf *storage);
int		convert_unsigned_octal(t_printf *storage);
int		convert_hexa(t_printf *storage);
int		convert_float(t_printf *storage);
int		convert_string(t_printf *storage);
int		convert_address(t_printf *storage);

int		convert_char(t_printf *storage);
int     convert_wchar(t_printf *storage);

/*
**	Additional functions
*/

void    print_width_field(int arg_len, int width, char sym);

#endif
