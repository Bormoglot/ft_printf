/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:42:53 by jbdoogls          #+#    #+#             */
/*   Updated: 2019/11/21 17:50:05 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  function printing symbols to fill width_field with ' ' or '0' (dependes on flag)
*/

void    print_width_field(int arg_len, int width, char sym)
{
    while (arg_len++ < width)
        ft_putchar(sym);
}
