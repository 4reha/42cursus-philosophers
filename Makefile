# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:26:02 by ael-hadd          #+#    #+#              #
#    Updated: 2022/03/04 18:18:38 by aourhzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

HEADER	=	philosophers.h

SRC		=	main.c ft_atoi.c routine.c ft_putnbr.c 


$(NAME)	:	$(HEADER) $(SRC)
	@cc -Wall -Werror -Wextra $(SRC) -o $(NAME)
	@@echo "\033[0;32mPhilo is ready ;)\033[0;32m"

all		:	$(NAME)

clean	:
	@rm -rf	$(NAME)
	@echo "\033[0;31mPhilo removed x\033[0;31m"

fclean	:	clean

re		:	fclean all