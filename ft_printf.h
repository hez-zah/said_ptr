/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:02:44 by sellyani          #+#    #+#             */
/*   Updated: 2024/11/24 16:03:53 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_digit(int nbr);
int	print_hexa(unsigned int nbr, char specifier);
int	print_ptr(unsigned long nbr);
int	print_str(char *str);
int	print_unsigned(unsigned int nbr);

#endif
