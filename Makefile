# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 15:46:39 by apcharpe          #+#    #+#              #
#    Updated: 2020/02/16 15:58:04 by apcharpe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = type_char.c \
	 parse_type.c \
	 parse_flags.c \
	 ft_itoa_base.c \
	 ft_printf.c \
	 ft_ulltoa_base.c \
	 ft_utoa.c \
	 type_hexa.c \
	 type_int.c \
	 type_percent.c \
	 type_pointer.c \
	 type_str.c \
	 type_unsigned.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME) : $(OBJS)
		cd libft && $(MAKE)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean:	clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C ./libft

re: fclean all

%.o:%.c
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)