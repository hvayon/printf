/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:52 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:01:39 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(t_flags *flags)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	s = va_arg(flags->args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->width > len)
	{
		while (i++ < flags->width - len)
			ft_putchar(' ');
		flags->total_length += flags->width - len;
	}
	flags->total_length += ft_putstr(s);
	return (flags->total_length);
}
