/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:54:18 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:00:34 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_flags *flags)
{
	char	c;

	c = va_arg(flags->args, int);
	if (flags->space == 1)
	{
		ft_putchar(' ');
		flags->total_length++;
	}
	write(1, &c, 1);
	flags->total_length += 1;
	return (flags->total_length);
}
