# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 17:26:59 by valentin          #+#    #+#              #
#    Updated: 2023/06/06 17:27:10 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++ -std=c++98
RM				= rm -f
WFLAGS		= -Wall -Wextra -Werror -I.

NAME			= easyfind
%.o: %.cpp
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