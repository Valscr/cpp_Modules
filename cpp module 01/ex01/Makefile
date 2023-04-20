# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 21:22:59 by valentin          #+#    #+#              #
#    Updated: 2023/04/20 21:57:14 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Zombie.cpp zombieHorde.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++ -std=c++98
RM				= rm -f
WFLAGS		= -Wall -Wextra -Werror -I.

NAME			= zombie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(WFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re