/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:03:29 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/25 05:03:29 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft_printf/libft_printf.h"
# include <stdio.h>

# define S_10 "0123456789"
# define BASE10 10
# define LHS_16 "0123456789abcdef"
# define UHS_16 "0123456789ABCDEF"
# define BASE16 16
# define C char
# define I int
# define ULI unsigned long long
# define UI unsigned int

typedef enum s_type
{
	TYPE_U,
	TYPE_LX,
	TYPE_UX
}	t_type;

int		ft_printf(const char *format, ...);
int		ft_print_i(int value);
int		ft_print_u(unsigned int value);
int		ft_print_x(unsigned int value, t_type type);
int		ft_print_p(unsigned long long value);
#endif