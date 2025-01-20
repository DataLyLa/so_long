/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:34:14 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:43:56 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"

int	ft_print_p(unsigned long long value)
{
	if (!value)
		return (ft_puts("(nil)"));
	return (ft_puts("0x") + ft_putn_ulli(value, BASE16, LHS_16));
}
