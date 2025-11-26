# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 10:33:52 by jojeda-p          #+#    #+#              #
#    Updated: 2025/05/14 10:33:55 by jojeda-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c handle.c handle2.c printf_utils.c printf_utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
