# Define Colors
BOLD_CYAN	= \033[1;36m
BOLD_RED	= \033[1;31m
RESET		= \033[0m

# Define Variables
MCHIHAB_SRCS =	srcs/ray-casting/init.c\
				srcs/ray-casting/drawing.c\
				srcs/ray-casting/move.c\
				srcs/ray-casting/move_utils.c\
				srcs/ray-casting/rendering3D.c\
				srcs/ray-casting/calculs.c\
				srcs/ray-casting/mouse.c\
				srcs/ray-casting/utils.c\
				srcs/ray-casting/minimap.c\
				srcs/ray-casting/animation.c\
				srcs/ray-casting/helper.c

ADIL_SRCS =		srcs/main.c\
				srcs/utils/check.c\
				srcs/utils/exit.c\
				srcs/utils/utils.c\
				srcs/utils/malloc.c\
				srcs/utils/init.c\
				srcs/parsing/parser_main.c\
				srcs/parsing/parser_textures.c\
				srcs/parsing/parser_colors.c\
				srcs/parsing/parser_map.c\
				srcs/parsing/parser_utils.c\
				srcs/parsing/parser_debug.c \
				srcs/parsing/parser_analyze.c\
				srcs/parsing/parser_check.c\
				srcs/parsing/parser_bonus.c

NAME		= 	cub3D
NAME_BONUS	=	cub3D_bonus
CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror#-fsanitize=address -g3
RM			= 	rm -f
SRCS		= 	$(ADIL_SRCS) $(MCHIHAB_SRCS)
OBJS		= 	$(SRCS:.c=.o)
INCLUDES	= 	-I/usr/include -Imlx
MLX_FLAGS	= 	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

# Define Rules
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make all -C libft > /dev/null
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L ./libft -lft
	@echo "$(BOLD_CYAN)"
	@echo "  ________        __    __________                   .___      "
	@echo " /  _____/  _____/  |_  \______   \ ____ _____     __| _/__.__."
	@echo "/   \  ____/ __ \   __\  |       _// __ \\__  \   / __  <   |  |"
	@echo "\    \_\  \  ___/|  |    |    |   \  ___/ / __ \_/ /_/ |\___  |"
	@echo " \______  /\___  >__|    |____|_  /\___  >____  /\____ |/ ____|"
	@echo "        \/     \/               \/     \/     \/      \/\/     "
	@echo "  __           __________.__                ._.                "
	@echo "_/  |_  ____   \______   \  | _____  ___.__.| |                "
	@echo "\   __\/  _ \   |     ___/  | \__  \<   |  || |                "
	@echo " |  | (  <_> )  |    |   |  |__/ __ \\___   | \|                "
	@echo " |__|  \____/   |____|   |____(____  / ____| __                "
	@echo "                                   \/\/      \/                "
	@echo "$(RESET)"

$(NAME_BONUS) : $(OBJS)
	@make all -C libft > /dev/null
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS) $(MLX_FLAGS) -L ./libft -lft
	@echo "$(BOLD_CYAN)"
	@echo "  ________        __    __________                   .___      "
	@echo " /  _____/  _____/  |_  \______   \ ____ _____     __| _/__.__."
	@echo "/   \  ____/ __ \   __\  |       _// __ \\__  \   / __  <   |  |"
	@echo "\    \_\  \  ___/|  |    |    |   \  ___/ / __ \_/ /_/ |\___  |"
	@echo " \______  /\___  >__|    |____|_  /\___  >____  /\____ |/ ____|"
	@echo "        \/     \/               \/     \/     \/      \/\/     "
	@echo "  __           __________.__                ._.                "
	@echo "_/  |_  ____   \______   \  | _____  ___.__.| |                "
	@echo "\   __\/  _ \   |     ___/  | \__  \<   |  || |                "
	@echo " |  | (  <_> )  |    |   |  |__/ __ \\___   | \|                "
	@echo " |__|  \____/   |____|   |____(____  / ____| __                "
	@echo "                                   \/\/      \/                "
	@echo "$(RESET)"

clean :
	@echo -n "$(BOLD_RED)"
	$(RM) $(OBJS)
	@echo -n "$(RESET)"
	@make clean -C libft > /dev/null

fclean :
	@echo -n "$(BOLD_RED)"
	$(RM) $(OBJS) $(NAME) $(NAME_BONUS)
	@echo -n "$(RESET)"
	@make fclean -C libft > /dev/null

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJS)
