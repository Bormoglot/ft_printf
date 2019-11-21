/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:42:21 by jbdoogls          #+#    #+#             */
/*   Updated: 2019/11/21 17:48:03 by jlavona          ###   ########.fr       */
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
    
    if (storage->length_mod == 3)
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
        printf ("}\ncharcount = " "%d\n", storage->charcount);                  // for testing
        printf ("width = " "%d\n", storage->min_width);                         // for testing
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


int     convert_int(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_unsigned_int(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_unsigned_octal(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_hexa(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_float(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_string(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}

int     convert_address(t_printf *storage)
{
    ft_putstr("converter not implemented.");
    return (0);
}