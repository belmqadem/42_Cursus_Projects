# Define Colors
GREEN   = \033[0;32m
RED		= \033[0;31m
RESET 	= \033[0m

# Define Variables
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAIN = mandatory/main.c

SRCS =	mandatory/parse_input.c\
		mandatory/sort_stack.c\
		mandatory/utils.c\
		mandatory/sort_utils.c\
		mandatory/parse_utils.c\
		mandatory/linked_list.c\
		mandatory/operations_1.c\
		mandatory/operations_2.c\
		mandatory/cases_a.c\
		mandatory/cases_b.c\
		mandatory/exec_rotation_b.c\
		mandatory/exec_rotation_a.c\
		mandatory/calculs.c

SRCS_BO =	bonus/checker_bonus.c\
			bonus/utils_bonus.c

MOBJ = $(MAIN:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJS_BO = $(SRCS_BO:.c=.o)

all : $(NAME)

.o : .c
	@$(CC) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(MOBJ)
	@make all -C libft > /dev/null
	$(CC) $(CFLAGS) $(OBJS) $(MOBJ) -o $(NAME) -L ./libft -lft
	@echo "$(GREEN) $(NAME) compiled successfully ✅$(RESET)"

bonus : $(BONUS)

$(BONUS) : $(OBJS_BO) $(OBJS)
	@make all -C libft > /dev/null
	$(CC) $(CFLAGS) $(OBJS_BO) $(OBJS) -o $(BONUS) -L ./libft -lft
	@echo "$(GREEN) Bonus compiled successfully ✅$(RESET)"

clean :
	@echo "$(RED) cleaning object files ...$(RESET)"
	@$(RM) $(OBJS) $(OBJS_BO) $(MOBJ)
	@make clean -C libft > /dev/null
	@sleep 0.5
	@echo "$(GREEN) cleaning is done ✅$(RESET)"

fclean :
	@echo "$(RED) full cleaning of $(NAME) ...$(RESET)"
	@$(RM) $(NAME) $(BONUS) $(OBJS) $(OBJS_BO) $(MOBJ)
	@make fclean -C libft > /dev/null
	@sleep 0.5
	@echo "$(GREEN) $(NAME) cleaned successfully ✅$(RESET)"

re : fclean all

.PHONY: all clean fclean re
