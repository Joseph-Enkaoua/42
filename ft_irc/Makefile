NAME	= ircserv
SRCDIR	= src
SRC		= $(wildcard $(SRCDIR)/*.cpp)
OBJDIR	= obj
OBJ		= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re