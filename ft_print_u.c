/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:04:21 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 15:34:01 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_tab_u(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_tab_u(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else if ((nb >= 0) && (nb <= 9))
		ft_putchar((nb % 10) + '0');
}

int	ft_print_u(t_flags *flags)
{
	unsigned int	u;

	u = va_arg(flags->args, unsigned int);
	flags->total_length += ft_numlen_u(u);
	ft_tab_u(u);
	return (flags->total_length);
}
