# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vess <vess@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 22:52:57 by jcampagn          #+#    #+#              #
#    Updated: 2021/12/10 10:58:57 by vess             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	ft_printf_hex.c \
	ft_printf_nb.c \
	ft_printf_nb.c \
	ft_printf_ptr.c \
	ft_printf_unsigned.c \


OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
.c.o:

			$(CC) $(CFLAGS) -I includes -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean :
				rm -f $(OBJS) $(OBJSBONUS)
fclean : clean
				rm -f $(NAME)
re : fclean all

 .PHONY: all clean fclean re
