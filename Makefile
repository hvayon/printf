# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 19:29:24 by hvayon            #+#    #+#              #
#    Updated: 2021/12/16 21:10:46 by hvayon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			= ft_printf.h
SRCS			=	ft_parse.c ft_print_c.c ft_strlen.c \
					ft_print_di.c ft_print_p.c ft_print_p.c \
					ft_print_s.c ft_print_u.c ft_print_xx.c \
					ft_printf.c ft_numlen.c ft_atoi.c \
					ft_numlen.c ft_putchar.c ft_putnbr.c ft_putstr.c \
					ft_print_perc.c ft_isdigit.c \
				
BONUS_SRCS		=	ft_parse_bonus.c ft_print_c_bonus.c ft_strlen_bonus.c \
					ft_print_di_bonus.c ft_print_p_bonus.c ft_print_p_bonus.c \
					ft_print_s_bonus.c ft_print_u_bonus.c ft_print_xx_bonus.c \
					ft_printf_bonus.c ft_numlen_bonus.c ft_atoi_bonus.c \
					ft_numlen_bonus.c ft_putchar_bonus.c ft_putnbr_bonus.c \
					ft_putstr_bonus.c ft_print_perc_bonus.c ft_isdigit_bonus.c \

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libftprintf.a

all: $(NAME)


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) $(HEADER)
	@touch bonus
	rm -f $(NAME)
	make "OBJS = $(BONUS_OBJS)" all

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f bonus

re:	fclean all

.PHONY: all clean fclean re
