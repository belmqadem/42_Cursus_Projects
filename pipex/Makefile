# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 02:06:42 by abel-mqa          #+#    #+#              #
#    Updated: 2024/02/07 09:52:51 by abel-mqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define Colors
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET 	= \033[0m

NAME = pipex

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	prog/pipex.c\
		prog/utils.c\
		libft/libft.a

SRCS_BONUS =	prog_bonus/pipex_bonus.c\
				prog_bonus/utils_1_bonus.c\
				prog_bonus/utils_2_bonus.c\
				libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS) libft/libft.a
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) > /dev/null
	@echo "$(GREEN)$(NAME) compiled successfully$(RESET)"

bonus : clean $(SRCS_BONUS) libft/libft.a
	@echo "$(YELLOW)Compiling $(NAME) bonus...$(RESET)"
	@$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
	@sleep 0.5
	@echo "$(GREEN)$(NAME) bonus compiled successfully$(RESET)"

libft/libft.a :
	@make -C libft > /dev/null

clean : 
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@make clean -C libft > /dev/null
	@sleep 0.5
	@echo "$(GREEN)Cleaned successfully$(RESET)"

fclean :
	@echo "$(YELLOW)Full cleaning...$(RESET)"
	@$(RM) $(NAME)
	@make fclean -C libft > /dev/null
	@sleep 0.5
	@echo "$(GREEN)Fully cleaned successfully$(RESET)"

re : fclean all
	@sleep 1.2
	@echo "$(BLUE)--Project rebuilt successfully--$(RESET)"
