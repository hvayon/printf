/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:30:48 by hvayon            #+#    #+#             */
/*   Updated: 2021/12/16 19:31:14 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	va_list	args;
	int		type;
	int		precision;
	int		zero;
	int		plus;
	int		minus;
	int		width;
	int		pointer;
	int		space;
	int		sharp;
	int		total_length;
}	t_flags;

void	ft_spec_parse(const char **str, t_flags *flags);
int		ft_numlen_u(unsigned int n);
int		ft_print_c(t_flags *flags);
int		ft_print_di(t_flags *flags);
int		ft_print_p(t_flags *flags);
int		ft_print_s(t_flags *flags);
int		ft_print_u(t_flags *flags);
int		ft_print_xx(t_flags *flags, int c);
void	init_struct(t_flags *flags);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_size_hex(t_flags *flags, unsigned int nb);
void	ft_tab_p(unsigned long long nb);
void	ft_tab_u(unsigned int nb);
void	ft_spec_print(t_flags *flags);
void	ft_tab_hex(unsigned int nb, int c);
int		ft_numlen(int n);
int		ft_atoi(const char *str);
void	ft_parse_prog(const char **str, t_flags *flags);
int		ft_strlen(char *str);
int		ft_putstr(char *s);
void	ft_putnbr(int nb);
int		ft_print_perc(t_flags *flags);
int		ft_isdigit(int c);

#endif
