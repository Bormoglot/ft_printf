/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:42:21 by jbdoogls          #+#    #+#             */
/*   Updated: 2019/11/21 21:14:48 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  func converting type char to type whar_t (or wint_t???)
**
**  TODO: 
**  1. Find correct type to convert
**  2. Write a function to convert
**  3. Write a func to print wchr_t (ft_putwchar?) - ???
*/

int     convert_wchar(t_printf *storage)
{
	int	tmp;
	
	tmp = va_arg(storage->ap, int);
	ft_putstr("wchar converter not implemented.");
	return (0);
}


/*
**  converter_func to type char (conv_spec = 'c')
**      if length = l -> convert wchar_t
**      if width != 0 -> print left \ right side of field;
*/

int     convert_char(t_printf *storage)
{
	char    char_to_print;
	
	if (storage->length_mod == EL)
		return (convert_wchar(storage));     // or wint (type wint_t)???
	else
	{
		char_to_print = (char) va_arg(storage->ap, int);
		if (storage->min_width && !storage->minus)
			print_width_field(1, storage->min_width, ' ');
		ft_putchar(char_to_print);
		if (storage->min_width && storage->minus)
			print_width_field(1, storage->min_width, ' ');
		storage->charcount += storage->min_width ? storage->min_width : 1;
		//printf ("}\ncharcount = " "%d\n", storage->charcount);                  // for testing
		//printf ("width = " "%d\n", storage->min_width);                         // for testing
		return (1);
	}
	return (0);
}


/*
**  In track_convertor we check the conv_spec and call relevant convert-function
**
**  applyed types:      d i o u x X     f       c s     p
**
*/

int     track_converters(t_printf *storage)
{
	if (storage->conv_spec == 'd' || storage->conv_spec == 'i')
		return (convert_int(storage));
	else if (storage->conv_spec == 'u')
		return (convert_unsigned_int(storage));
	else if (storage->conv_spec == 'o')
		return (convert_unsigned_octal(storage));
	else if (storage->conv_spec == 'x' || storage->conv_spec == 'X')
		return (convert_hexa(storage));
	else if (storage->conv_spec == 'f')
		return (convert_float(storage));
	else if (storage->conv_spec == 'c')
		return (convert_char(storage));
	else if (storage->conv_spec == 's')
		return (convert_string(storage));
	else if (storage->conv_spec == 'p')
		return (convert_address(storage));
	return (0);
}



/*
**  yet not implemented converters - drafts to avoid gcc errors
*/

/*
** convert_int() currently works with:
** 	min_width, '-', '+', 
*/

int     convert_int(t_printf *storage)
{
	int		value;
	char	*str;
	size_t	len;
	
	value = va_arg(storage->ap, int);
	value < 0 ? (storage->plus = false) : 0;
	str = ft_itoa(value);
	if (str)
	{
		len = storage->plus ? (ft_strlen(str) + 1) : ft_strlen(str);
		if (storage->min_width && !storage->minus)
			print_width_field(len, storage->min_width, ' ');
		if (storage->plus)
			ft_putchar('+');
		ft_putstr(str);
		if (storage->min_width && storage->minus)
			print_width_field(len, storage->min_width, ' ');
		storage->charcount += storage->min_width ? storage->min_width : len;
		return (1);
	}
	return (0);
}

int     convert_unsigned_int(t_printf *storage)
{
	unsigned int	tmp;
	
	tmp = va_arg(storage->ap, unsigned int);
	ft_putstr("unsigned int converter not implemented.");
	return (0);
}

int     convert_unsigned_octal(t_printf *storage)
{
	unsigned int	tmp;
	
	tmp = va_arg(storage->ap, unsigned int);
	ft_putstr("unsigned octal converter not implemented.");
	return (0);
}

int     convert_hexa(t_printf *storage)
{
	unsigned int	tmp;
	
	tmp = va_arg(storage->ap, unsigned int);
	ft_putstr("hexa converter not implemented.");
	return (0);
}

int     convert_float(t_printf *storage)
{
	double	tmp;
	
	tmp = va_arg(storage->ap, double);
	ft_putstr("float converter not implemented.");
	return (0);
}

int     convert_string(t_printf *storage)
{
	char	*tmp;

	tmp = va_arg(storage->ap, char *);	
	ft_putstr("string converter not implemented.");
	return (0);
}

int     convert_address(t_printf *storage)
{
	void	*tmp;

	tmp = va_arg(storage->ap, void *);
	ft_putstr("address converter not implemented.");
	return (0);
}