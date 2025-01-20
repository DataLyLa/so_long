/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:39:55 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:39:43 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putn_ui(unsigned int value, int base, char *s_base)
{
	int	count;

	count = 0;
	if (value < (unsigned int)base)
		count += ft_putc(s_base[value]);
	else
	{
		count += ft_putn_ui(value / base, base, s_base);
		count += ft_putc(s_base[value % base]);
	}
	return (count);
}
