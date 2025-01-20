/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:34:14 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:43:25 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"

int	ft_print_i(int value)
{
	int		num;
	int		minus;

	if (value == -2147483648)
		return (ft_puts("-2147483648"));
	minus = 0;
	num = ft_absolute(value, &minus);
	if (minus == 1)
		ft_putc('-');
	return (ft_putn_i(num, BASE10, S_10) + minus);
}
