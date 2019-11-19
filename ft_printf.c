/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:48:44 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/19 21:00:50 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO
** 1.	Write a function that resets to zero all the fields in the structure (except
** 		`charcount`, `ap` and `format`) before the next `%`.
**
** 2.	Finish the `parse_percision` function.
*/

void	parse_precision(t_printf *storage)
{
	char	*ptr;

	ptr = F_PTR;
	
}

void	parse_min_width(t_printf *storage)
{
	char	*ptr;

	ptr = F_PTR;
	if (*ptr != '\0' && ft_isdigit(*ptr))
		storage->min_width = ft_atoi(ptr);
	while (*F_PTR != '\0' && ft_isdigit(*F_PTR))
		++F_PTR;
}

void	parse_flags(t_printf *storage)
{
	while (*F_PTR != '\0' && (*F_PTR == '#' || *F_PTR == '0' || *F_PTR == '-'
	|| *F_PTR == ' ' || *F_PTR == '+'))
	{
		if (*F_PTR == '#')
			storage->hash = true;
		if (*F_PTR == '0')
			storage->zero = true;
		if (*F_PTR == '-')
		{
			storage->minus = true;
			storage->zero = false;
		}
		if (*F_PTR == ' ')
			storage->space = true;
		if (*F_PTR == '+')
		{
			storage->plus = true;
			storage->space = false;
		}
		++F_PTR;
	}
}

void	parse_format(t_printf *storage)
{
	char	char_to_print;

	parse_flags(storage);
	parse_min_width(storage);
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
			++storage.format;
			parse_format(&storage);
		}
		else
		{
			ft_putchar(*storage.format);
			++storage.charcount;
		}
		++storage.format;
	}
	va_end(storage.ap);
	printf("storage->min_width is <%d>\n", storage.min_width);
	return (storage.charcount);
}
