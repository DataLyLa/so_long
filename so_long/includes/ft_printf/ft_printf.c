/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylaurol <lylaurol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:04:13 by lylaurol          #+#    #+#             */
/*   Updated: 2024/07/25 05:04:13 by lylaurol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf.h"
#include <stdio.h>

static int	parse_format(const char *format, va_list args)
{
	int	count;

	if (!*format || !args)
		return (0);
	count = 0;
	if (*format == 'c')
		count += ft_putc(va_arg(args, I));
	if (*format == 's')
		count += ft_puts(va_arg(args, C *));
	if (*format == 'd' || *format == 'i')
		count += ft_print_i(va_arg(args, I));
	if (*format == 'u')
		count += ft_print_u(va_arg(args, UI));
	if (*format == 'p')
		count += ft_print_p(va_arg(args, ULI));
	if (*format == 'x')
		count += ft_print_x(va_arg(args, UI), TYPE_LX);
	if (*format == 'X')
		count += ft_print_x(va_arg(args, UI), TYPE_UX);
	if (*format == '%')
		count += ft_putc('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;

	i = -1;
	if (!*format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			count += parse_format(&format[i + 1], args);
			++i;
		}
		else
			count += ft_putc(*(format + i));
	}
	va_end(args);
	return (count);
}

//  int main(void)
// {
// 	char *s = NULL;
// 	printf(" |%i| ", printf("%p\n",&s));
// 	printf("|%i| ", ft_printf("%p",&s));
// 	// ft_printf("%x\n", 100);
// 	// ft_printf("xhy : %s\n", "heuehkn");
// 	// ft_putn_ui(42, BASE16,UHS_16);
// 	// printf("\n mine %u\n", ft_putn_ui(42,BASE16, UHS_16));
// 	// ft_printf("me : %u\n", -42);
// 	// ft_printf("mine : %u\n", 0);
// 	// ft_printf("mine : %u\n", 424);
// 	// // printf("u2 %u\n", 0);
// 	// printf("u3 %p\n", -1);
// 	// printf("u4 %u\n", -100);
// 	// printf("u5 %u\n", 56);
// 	// printf("hex 2 %x\n", 0);
// 	// printf("hex 2 %x\n", -1);
// 	// printf("hex 2 %x\n", 135);
// 	// printf("real %u\n", -42);
// 	ft_printf("hex 2 %p\n", -1);
// 	return (0);
// }