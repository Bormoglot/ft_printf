/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:38 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/20 20:57:21 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	parse_conv_spec(t_printf *storage)
{
	char	ch;
	
	ch = *storage->format;
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' || ch == 'i' || ch == 'o'
	|| ch == 'u' || ch == 'x' || ch == 'X' || ch == '%')
		storage->conv_spec = ch;
}

void	parse_length_mod(t_printf *storage)
{
	while (*storage->format == 'h' || *storage->format == 'l'
	|| *storage->format == 'L')
	{
		if (*storage->format == 'h' && storage->length_mod == H)
			storage->length_mod = HH;
		else if (*storage->format == 'h' && storage->length_mod == 0)
			storage->length_mod = H;
		else if (*storage->format == 'l' && storage->length_mod == EL)
			storage->length_mod = ELEL;
		else if (*storage->format == 'l' && storage->length_mod == 0)
			storage->length_mod = EL;
		else if (*storage->format == 'L' && storage->length_mod == 0)
			storage->length_mod = L;
		++(storage->format);
	}
}

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
