# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:26:02 by ael-hadd          #+#    #+#              #
#    Updated: 2022/03/06 14:31:58 by ael-hadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

HEADER	=	philosophers.h

SRC		=	main.c ft_atoi.c routine.c errors.c finish.c print.c


$(NAME)	:	$(HEADER) $(SRC)
	@cc -Wall -Werror -Wextra $(SRC) -o $(NAME)
	
	@echo "╱╱╱╭╮╱╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╭╮"
	@echo "╱╱╱┃┃╱╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱┃┃"
	@echo "╭━━┫╰━┳┫┃╭━━┳━━┳━━┳━━┫╰━┳━━┳━┳━━╮"
	@echo "┃╭╮┃╭╮┣┫┃┃╭╮┃━━┫╭╮┃╭╮┃╭╮┃┃━┫╭┫━━┫"
	@echo "┃╰╯┃┃┃┃┃╰┫╰╯┣━━┃╰╯┃╰╯┃┃┃┃┃━┫┃┣━━┃"
	@echo "┃╭━┻╯╰┻┻━┻━━┻━━┻━━┫╭━┻╯╰┻━━┻╯╰━━╯"
	@echo "┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃ by ael-hadd"
	@echo "╰╯╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯"
	@echo "\033[0;32mPhilo is ready ;)\033[0;32m"

all		:	$(NAME)

clean	:
	@rm -rf	$(NAME)
	@echo "\033[0;31mPhilo removed x\033[0;31m"

fclean	:	clean

re		:	fclean all