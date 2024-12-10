GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = form28B
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled.$(RESET)"

clean :
	@echo "$(RED)"
	rm -f $(OBJS)
	@echo "$(RESET)"

fclean :
	@echo "$(RED)"
	rm -f $(OBJS) $(NAME)
	@echo "$(RESET)"

re : fclean all

.PHONY : all clean fclean re
