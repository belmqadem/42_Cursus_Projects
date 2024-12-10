GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = serialize
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled.$(RESET)"

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
