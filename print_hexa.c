/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:01:34 by sellyani          #+#    #+#             */
/*   Updated: 2024/11/24 16:32:02 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int nbr, char specifier)
{
	int		count;

	count = 0;
	if (nbr >= 16)
	{
		count += print_hexa(nbr / 16, specifier);
		count += print_hexa(nbr % 16, specifier);
	}
	else
	{
		if (nbr <= 9)
			count += print_char(nbr + '0');
		else
		{
			if (specifier == 'x')
				count += print_char(nbr % 10 + 'a');
			else if (specifier == 'X')
				count += print_char(nbr % 10 + 'A');
		}
	}
	return (count);
}
