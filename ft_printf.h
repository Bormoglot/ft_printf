/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:08:17 by jlavona           #+#    #+#             */
/*   Updated: 2019/11/20 15:58:07 by jlavona          ###   ########.fr       */
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
*/

typedef struct		s_printf
{
	int		charcount;
	char	*format;
	va_list	ap;
	bool	hash;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	int		min_width;
	bool	is_precision;
	int		precision;
}					t_printf;


int					ft_printf(char *format, ...);

#endif