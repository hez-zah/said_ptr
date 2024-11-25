/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:01:10 by sellyani          #+#    #+#             */
/*   Updated: 2024/11/24 17:33:15 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(*ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(*ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += print_hexa(va_arg(*ap, unsigned int), specifier);
	else if (specifier == 'p')
		count += print_ptr(va_arg(*ap, unsigned long long));
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start (ap, format);
	count = 0 ;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), &ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	int cout = ft_printf("%%%%%%\n", 42);
// 	int fout = printf("%%%%%%\n");
// 	printf("%d   %d\n", cout, fout);
// 	// ft_printf("%c%c%c", 'a', 'd', 'b');
// 	// int count = ft_printf("||\001\002\007\v\010\f\r\n");
// 	// printf("=======");
// 	// int fount = printf("||\001\002\007\v\010\f\r\n");
// 	// printf("=======\n");
// 	// printf("%d | %d\n", count, fount);
// 	// printf("%s", (char *)NULL);
// 	// ft_printf("%d", INT_MIN);
// 	// printf("\n\n");
// 	// printf("%d", INT_MIN);
//     // ft_printf("Hello, %s!\n", "world");
//     // ft_printf("Character: %c\n", 'A');
//     // ft_printf("Decimal: %d\n", -42);
//     // ft_printf("Unsigned: %u\n", 42);
//     // ft_printf("Hexadecimal: %X\n", 255);
//     // ft_printf("Pointer: %p\n\n", &main);
// }