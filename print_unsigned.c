/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:01:45 by sellyani          #+#    #+#             */
/*   Updated: 2024/11/24 16:01:46 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 10)
		count += print_char(nbr + '0');
	else
	{
		count += print_unsigned(nbr / 10);
		count += print_unsigned(nbr % 10);
	}
	return (count);
}
