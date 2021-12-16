/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:40 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:02:05 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_hex(t_flags *flags, unsigned int nb)
{
	int	size;

	size = 0;
	if (flags->sharp == 1)
		size += 2;
	if (nb == 0)
		size = 1;
	while (nb)
	{
		nb = nb / 16;
		size++;
	}
	return (size);
}

void	ft_hex_bonus(int c, t_flags *flags)
{
	if (flags->sharp == 1)
	{
		if (c == 1)
			ft_putstr("0x");
		else if (c == 0)
			ft_putstr("0X");
	}
}

void	ft_tab_hex(unsigned int nb, int c)
{
	char	store[64];
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (nb)
	{
		if ((nb % 16) < 10)
			store[j++] = (nb % 16) + '0';
		else
			store[j++] = (nb % 16) + (87 * (c == 1)) + (55 * (c == 0));
		nb /= 16;
	}
	store[j--] = '\0';
	while (i < j)
	{
		tmp = store[i];
		store[i] = store[j];
		store[j] = tmp;
		i++;
		j--;
	}
	ft_putstr(store);
}

int	ft_print_xx(t_flags *flags, int c)
{
	unsigned int	nb;

	nb = va_arg(flags->args, unsigned int);
	if (nb == 0)
	{
		ft_putchar('0');
		return (flags->total_length++);
	}
	flags->total_length += ft_size_hex(flags, nb);
	ft_hex_bonus(c, flags);
	ft_tab_hex(nb, c);
	return (flags->total_length);
}
