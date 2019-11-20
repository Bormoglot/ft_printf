/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:48:44 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/20 17:15:22 by jlavona          ###   ########.fr       */
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

/*
** What if the precision number is longer than an int?
*/

void	parse_precision(t_printf *storage)
{
	char	*ptr;

	if (*storage->format == '.')
	{
		storage->is_precision = true;
		storage->precision = 0;
		++(storage->format);
		ptr = storage->format;
		if (ft_isdigit(*ptr))
			storage->precision = ft_atoi(ptr);
		while (ft_isdigit(*storage->format))
			++(storage->format);
	}	
}

/*
** What if the min_width number is longer than an int?
*/

void	parse_min_width(t_printf *storage)
{
	char	*ptr;

	ptr = storage->format;
	if (ft_isdigit(*ptr))
		storage->min_width = ft_atoi(ptr);
	while (ft_isdigit(*storage->format))
		++(storage->format);
}

void	parse_flags(t_printf *storage)
{
	while (*storage->format == '#' || *storage->format == '0' || *storage->format == '-'
	|| *storage->format == ' ' || *storage->format == '+')
	{
		if (*storage->format == '#')
			storage->hash = true;
		if (*storage->format == '0')
			storage->zero = true;
		if (*storage->format == '-')
		{
			storage->minus = true;
			storage->zero = false;
		}
		if (*storage->format == ' ')
			storage->space = true;
		if (*storage->format == '+')
		{
			storage->plus = true;
			storage->space = false;
		}
		++(storage->format);
	}
}

void	parse_format(t_printf *storage)
{
	char	char_to_print;

	parse_flags(storage);
	parse_min_width(storage);
	parse_precision(storage);
	if (*(storage->format) == '%')
	{
		ft_putchar('%');
		++(storage->charcount);
	}
	else if (*(storage->format) == 'c')
	{
		char_to_print = (char)va_arg(storage->ap, int);
		ft_putchar(char_to_print);
		++(storage->charcount);
	}
	else
	{
		char_to_print = (char)va_arg(storage->ap, int);
		ft_putstr("Not implemented.");
	}
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
		}
		else
		{
			ft_putchar(*storage.format);
			++(storage.charcount);
		}
		++storage.format;
	}
	va_end(storage.ap);
	printf("storage->precision is <%d>\n", storage.precision);
	printf("storage->is_precision is <%d>\n", storage.is_precision);
	return (storage.charcount);
}
