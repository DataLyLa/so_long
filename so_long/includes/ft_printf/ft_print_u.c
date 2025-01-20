/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 07:34:14 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:34:23 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"

int	ft_print_u(unsigned int value)
{
	unsigned int	num;
	int				minus;

	minus = 0;
	num = ft_absolute(value, &minus);
	return (ft_putn_ui(num, BASE10, S_10));
}
