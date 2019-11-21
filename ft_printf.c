/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:48:44 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/21 17:47:39 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO
** 1.	Write a function that resets to zero all the fields in the structure (except
** 		`charcount`, `ap` and `format`) before the next `%`.
**
** 2.
*/

void	convert(t_printf *storage)
{	
	if (storage->conv_spec == '%')
	{
		ft_putchar('%');
		++(storage->charcount);
	}
	else
		if (!(track_converters(storage)))
			ft_putstr("track_converters() error");
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
		}
		else
		{
			ft_putchar(*storage.format);
			++(storage.charcount);
		}
		++storage.format;
	}
	va_end(storage.ap);
	printf("storage->length_mod is <%d>\n", storage.length_mod);
	printf("storage->is_precision is <%d>\n", storage.is_precision);
	return (storage.charcount);
}
