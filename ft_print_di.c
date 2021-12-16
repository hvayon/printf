/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:08 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 18:39:45 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(t_flags *flags)
{
	int	d;

	d = va_arg(flags->args, int);
	flags->total_length += ft_numlen(d) + (d < 0);
	if ((flags->plus == 1 && flags->space == 1) || (flags->plus == 1))
	{
		if (d >= 0)
		{
			ft_putchar('+');
			flags->total_length++;
		}
	}
	if (flags->space == 1 && flags->plus != 1)
	{
		if (d >= 0)
		{
			ft_putchar(' ');
			flags->total_length++;
		}
	}
	ft_putnbr(d);
	return (flags->total_length);
}
