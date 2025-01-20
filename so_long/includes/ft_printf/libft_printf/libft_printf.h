/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 07:43:17 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/30 03:38:05 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_putc(char c);
int		ft_puts(char *s);
int		ft_putn_i(int value, int base, char *s_base);
int		ft_putn_ui(unsigned int value, int base, char *s_base);
int		ft_putn_ulli(unsigned long long value, int base, char *s_base);
int		ft_absolute(long long value, int *minus);
#endif