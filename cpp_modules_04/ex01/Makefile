# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:04:19 by vescaffr          #+#    #+#              #
#    Updated: 2023/05/24 16:27:44 by vescaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS			= $(SRCS:.cpp=.o)
DEPS			= $(SRCS:.cpp=.hpp)

CC				= c++ -std=c++98
RM				= rm -f
WFLAGS		= -Wall -Wextra -Werror -I.

NAME			= animal
%.o: %.cpp $(DEPS)
	$(CC) $(WFLAGS) -c $<
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(WFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re