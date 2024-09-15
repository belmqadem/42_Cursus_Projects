# Define Colors
GREEN   = \033[0;32m
RED		= \033[0;31m
RESET 	= \033[0m
YELLOW  = \033[0;93m

# Define Variables
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
SRCS =	srcs/main.c\
		srcs/free.c\
		srcs/utils.c\
		srcs/utils2.c\
		srcs/parsing/env.c\
		srcs/parsing/parser.c\
		srcs/parsing/parser_utils.c\
		srcs/parsing/quotes.c\
		srcs/parsing/lexer.c\
		srcs/parsing/lexer_utils.c\
		srcs/parsing/lexer_utils2.c\
		srcs/parsing/expand.c\
		srcs/parsing/expand_utils.c\
		srcs/parsing/expand_utils2.c\
		srcs/parsing/commands.c\
		srcs/parsing/commands_utils.c\
		srcs/parsing/redirect_utils.c\
		srcs/parsing/redirect.c\
		srcs/parsing/heredoc.c\
		srcs/parsing/heredoc_utils.c\
		srcs/parsing/heredoc_utils2.c\
		srcs/parsing/heredoc_sig.c\
		srcs/execution/builtins/my_own_cd.c\
		srcs/execution/builtins/my_own_unset.c\
		srcs/execution/builtins/my_own_export.c\
		srcs/execution/builtins/my_own_exit.c\
		srcs/execution/builtins/utils/utils_exit.c\
		srcs/execution/builtins/utils/utils_built.c\
		srcs/execution/builtins/utils/utils_export.c\
		srcs/execution/builtins/utils/utils_export2.c\
		srcs/execution/builtins/utils/utils_cd.c\
		srcs/execution/builtins/utils/utils_cd_2.c\
		srcs/execution/builtins/my_own_echo.c\
		srcs/execution/builtins/my_own_env.c\
		srcs/execution/builtins/my_own_pwd.c\
		srcs/execution/excute_cmnd/executor.c\
		srcs/execution/excute_cmnd/is_cmd_exist.c\
		srcs/execution/excute_cmnd/utils_excute.c\
		srcs/execution/excute_cmnd/utils_excute2.c\
		srcs/execution/excute_cmnd/utils_excute3.c\
		srcs/execution/excute_cmnd/utils_excute4.c\
		srcs/execution/excute_cmnd/utils.c\
		srcs/execution/excute_cmnd/shlvl.c\
		srcs/execution/signals/signals.c\
		srcs/execution/signals/utils_signals.c\

OBJS = $(SRCS:.c=.o)

LDLIBS = -lreadline

# define rules
all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	@echo "$(GREEN)  _   _   _   _   _   _   _   _   _  "
	@sleep 0.05
	@echo " / \ / \ / \ / \ / \ / \ / \ / \ / \ "
	@sleep 0.05
	@echo "( M | I | N | I | S | H | E | L | L )"
	@sleep 0.05
	@echo " \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ "
	@sleep 0.05
	@echo "                                     $(RESET)"
	@make all -C libft > /dev/null
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./libft -lft $(LDLIBS)

clean :
	@echo -n "$(YELLOW)"
	$(RM) $(OBJS)
	@echo -n "$(RESET)"
	@make clean -C libft > /dev/null

fclean :
	@echo -n "$(YELLOW)"
	$(RM) $(OBJS) $(NAME)
	@echo -n "$(RESET)"
	@make fclean -C libft > /dev/null

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJS)
