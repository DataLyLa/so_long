/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:42:41 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:44:47 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putn_i(int value, int base, char *s_base)
{
	int	count;

	count = 0;
	if (base <= 1 || s_base == NULL)
		return (0);
	if (value >= base)
		count += ft_putn_i(value / base, base, s_base);
	count += ft_putc(s_base[value % base]);
	return (count);
}
