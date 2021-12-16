/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:40 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 20:29:59 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_parse(const char **str, t_flags *flags)
{
	if (**str == '#')
		flags->sharp = 1;
	if (**str == '0')
		flags->zero = 1;
	if (**str == '-')
		flags->minus = 1;
	if (**str == ' ')
		flags->space = 1;
	if (**str == '+')
		flags->plus = 1;
}

void	ft_spec_parse(const char **str, t_flags *flags)
{
	flags->type = **str;
}

void	ft_spec_print(t_flags *flags)
{
	if (flags->type == 'c')
		ft_print_c(flags);
	if (flags->type == 's')
		ft_print_s(flags);
	if (flags->type == 'd' || flags->type == 'i')
		ft_print_di(flags);
	if (flags->type == 'x' || flags->type == 'X')
		ft_print_xx(flags, flags->type == 'x');
	if (flags->type == 'p')
		ft_print_p(flags);
	if (flags->type == 'u')
		ft_print_u(flags);
	if (flags->type == '%')
		ft_print_perc(flags);
}

static int	check(const char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_parse_prog(const char **str, t_flags *flags)
{
	while (check(**str, "# -+0"))
	{
		ft_flag_parse(str, flags);
		(*str)++;
	}
	if (ft_isdigit(**str))
	{
		flags->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		flags->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	ft_spec_parse(str, flags);
	ft_spec_print(flags);
}
