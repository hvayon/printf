/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:07:15 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:02:20 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_flags *flags)
{
	flags->total_length = 0;
	flags->plus = 0;
	flags->sharp = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
}

int	ft_printf(const char *str, ...)
{
	t_flags	flags;

	init_struct(&flags);
	va_start(flags.args, str);
	while (*str)
	{
		if (*str == '%')
		{	
			str++;
			ft_parse_prog(&str, &flags);
		}
		else
			flags.total_length += write(1, str, 1);
		str++;
	}
	va_end(flags.args);
	return (flags.total_length);
}
