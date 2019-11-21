/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:48:44 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/21 20:20:30 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO
** 1.
**
** 2.
*/

void	reset_fields(t_printf *storage)
{
	storage->hash = false;
	storage->zero = false;
	storage->minus = false;
	storage->space = false;
	storage->plus = false;
	storage->min_width = 0;
	storage->is_precision = false;
	storage->precision = 0;
	storage->length_mod = 0;
	storage->conv_spec = 0;
}

void	convert(t_printf *storage)
{	
	if (storage->conv_spec == '%')
	{
		ft_putchar('%');
		++(storage->charcount);
	}
	else
		if (!(track_converters(storage)))
			ft_putstr(" track_converters() error ");
}

void	parse_format(t_printf *storage)
{
	parse_flags(storage);
	parse_min_width(storage);
	parse_precision(storage);
	parse_length_mod(storage);
	parse_conv_spec(storage);
}

int		ft_printf(char *format, ...)
{
	t_printf	storage;

	ft_bzero(&storage, sizeof(storage));
	storage.format = format;
	va_start(storage.ap, format);
	while (*storage.format != '\0')
	{
		if (*storage.format == '%')
		{
			++(storage.format);
			parse_format(&storage);
			convert(&storage);
			reset_fields(&storage);
		}
		else
		{
			ft_putchar(*storage.format);
			++(storage.charcount);
		}
		++storage.format;
	}
	va_end(storage.ap);
	//printf("storage->length_mod is <%d>\n", storage.length_mod);
	//printf("storage->is_precision is <%d>\n", storage.is_precision);
	return (storage.charcount);
}
