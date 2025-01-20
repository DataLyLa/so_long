/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_ulli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:39:55 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:44:36 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putn_ulli(unsigned long long value, int base, char *s_base)
{
	unsigned long long	num;
	unsigned long long	n_base;
	int					count;

	n_base = (unsigned long long)base;
	count = 0;
	num = value;
	if (num < n_base)
	count += ft_putc(s_base[num]);
	else
	{
	count += ft_putn_ulli((num / n_base), base, s_base);
	count += ft_putc(s_base[num % n_base]);
	}
	return (count);
}
