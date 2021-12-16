/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:59:31 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:01:19 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_perc(t_flags *flags)
{
	if (flags->type == '%')
	{
		ft_putchar('%');
		flags->total_length++;
	}
	return (flags->total_length);
}
