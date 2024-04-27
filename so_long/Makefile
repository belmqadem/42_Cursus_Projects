# Define Colors
GREEN   = \033[0;32m
RESET 	= \033[0m

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =	srcs/main.c\
		srcs/utils.c\
		srcs/parse_map.c\
		srcs/checks.c\
		srcs/window.c\
		srcs/hooks.c\
		srcs/utils2.c\
		srcs/moves.c\
		srcs/play.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

$(NAME) : $(OBJS)
	@make all -C libft > /dev/null
	@$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS) -L ./libft -lft
	@echo "$(GREEN) $(NAME) compiled successfully ✅ $(RESET)"

clean :
	@echo " "
	@echo "⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳         ⏳           ⏳⏳⏳⏳⏳    ⏳      ⏳    ⏳⏳⏳⏳⏳          "
	@sleep 0.1
	@echo "⏳           ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳    ⏳    ⏳                 "
	@sleep 0.1
	@echo "⏳           ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳⏳  ⏳    ⏳               "
	@sleep 0.1
	@echo "⏳⏳⏳⏳⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳⏳⏳⏳    ⏳  ⏳⏳⏳       "
	@sleep 0.1
	@echo "        ⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳  ⏳⏳⏳    ⏳  ⏳  ⏳       "
	@sleep 0.1
	@echo "        ⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳    ⏳⏳    ⏳      ⏳        "
	@sleep 0.1
	@echo "⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳         ⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳    ⏳      ⏳    ⏳⏳⏳⏳⏳         "
	@echo " "
	@sleep 0.1
	@$(RM) $(OBJS)
	@make clean -C libft > /dev/null

fclean :
	@echo " "
	@echo "⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳         ⏳           ⏳⏳⏳⏳⏳    ⏳      ⏳    ⏳⏳⏳⏳⏳          "
	@sleep 0.1
	@echo "⏳           ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳    ⏳    ⏳                 "
	@sleep 0.1
	@echo "⏳           ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳⏳  ⏳    ⏳               "
	@sleep 0.1
	@echo "⏳⏳⏳⏳⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳⏳⏳⏳⏳    ⏳  ⏳⏳⏳       "
	@sleep 0.1
	@echo "        ⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳  ⏳⏳⏳    ⏳  ⏳  ⏳       "
	@sleep 0.1
	@echo "        ⏳   ⏳      ⏳         ⏳           ⏳      ⏳    ⏳    ⏳⏳    ⏳      ⏳        "
	@sleep 0.1
	@echo "⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳         ⏳⏳⏳⏳⏳   ⏳⏳⏳⏳⏳    ⏳      ⏳    ⏳⏳⏳⏳⏳         "
	@echo " "
	@sleep 0.1
	@$(RM) $(OBJS) $(NAME)
	@make fclean -C libft > /dev/null

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJS)
