NAME		= easyfind
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= main.cpp
OBJS		= ${SRCS:.cpp=.o}
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		c++ $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re