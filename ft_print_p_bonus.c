/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:03:09 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:01:04 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int	ft_size_p(unsigned long long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size = 1;
	while (nb)
	{
		nb = nb / 16;
		size++;
	}
	return (size);
}

void	ft_tab_p(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_tab_p(nb / 16);
		if ((nb % 16) < 10)
			ft_putchar((nb % 16) + '0');
		else
			ft_putchar((nb % 16) + 87);
	}
	else if (nb < 16)
	{
		if ((nb % 16) < 10)
			ft_putchar((nb % 16) + '0');
		else
			ft_putchar((nb % 16) + 87);
	}
}

int	ft_print_p(t_flags *flags)
{
	unsigned long	nb;
	char			*p;

	p = "0x";
	nb = va_arg(flags->args, unsigned long);
	flags->total_length += ft_size_p(nb);
	flags->total_length += ft_strlen(p);
	if (flags->space == 1)
	{
		ft_putchar(' ');
		flags->total_length++;
	}
	if (nb == 0)
		ft_putstr("0x0");
	else
	{
		ft_putstr(p);
		ft_tab_p(nb);
	}
	return (flags->total_length);
}
