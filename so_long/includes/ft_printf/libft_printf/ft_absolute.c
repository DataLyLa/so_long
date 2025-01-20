/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 07:28:19 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:35:18 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_absolute(long long value, int *minus)
{
	if (value < 0)
	{
		value = -value;
		*minus = 1;
	}
	return (value);
}
