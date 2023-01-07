NAME	= phonebook
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp PhoneBook.cpp Contact.cpp
OBJS	= ${SRCS:.cpp=.o}
RM		= rm -rf
all: $(NAME)

$(NAME): $(OBJS)
	c++ -g $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
