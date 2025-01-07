# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdu <sdu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:18:59 by sdu               #+#    #+#              #
#    Updated: 2025/01/07 16:15:10 by sdu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc
SRC			= ft_printf.c ft_printhexa.c ft_printptr.c ft_print_base10.c ft_side_ft.c
OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re