# Define Colors
GREEN   = \033[0;32m
RED		= \033[0;31m
RESET 	= \033[0m

# Define Variables
NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

RM = rm -rf

SRCS =	srcs/main.c\
		srcs/utils.c\
		srcs/parse.c\
		srcs/setup.c\
		srcs/simulation.c\
		srcs/diner.c\
		srcs/cleanup.c

OBJS = $(SRCS:.c=.o)

# define rules
all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗"
	@sleep 0.02
	@echo "║                                                                                                   ║"
	@sleep 0.02
	@echo "║    ____  __ __  ____  _       ___          __   ___   ___ ___  ____  ____  _        ___  ___      ║"
	@sleep 0.02
	@echo "║   |    \|  T  Tl    j| T     /   \        /  ] /   \ |   T   T|    \l    j| T      /  _]|   \     ║"
	@sleep 0.02
	@echo "║   |  o  )  l  | |  T | |    Y     Y      /  / Y     Y| _   _ ||  o  )|  T | |     /  [_ |    \    ║"
	@sleep 0.02
	@echo "║   |   _/|  _  | |  | | l___ |  O  |     /  /  |  O  ||  \_/  ||   _/ |  | | l___ Y    _]|  D  Y   ║"
	@sleep 0.02
	@echo "║   |  |  |  |  | |  | |     T|     |    /   \_ |     ||   |   ||  |   |  | |     T|   [_ |     |   ║"
	@sleep 0.02
	@echo "║   |  |  |  |  | j  l |     |l     !    \     |l     !|   |   ||  |   j  l |     ||     T|     |   ║"
	@sleep 0.02
	@echo "║   l__j  l__j__j|____jl_____j \___/      \____j \___/ l___j___jl__j  |____jl_____jl_____jl_____j   ║"
	@sleep 0.02
	@echo "║                                                                                                   ║"
	@sleep 0.02
	@echo "║     _____ __ __    __    __    ___  _____ _____ _____  __ __  _      _      __ __                 ║"
	@sleep 0.02
	@echo "║    / ___/|  T  T  /  ]  /  ]  /  _]/ ___// ___/|     ||  T  T| T    | T    |  T  T                ║"
	@sleep 0.02
	@echo "║   (   \_ |  |  | /  /  /  /  /  [_(   \_(   \_ |   __j|  |  || |    | |    |  |  |                ║"
	@sleep 0.02
	@echo "║    \__  T|  |  |/  /  /  /  Y    _]\__  T\__  T|  l_  |  |  || l___ | l___ |  ~  |                ║"
	@sleep 0.02
	@echo "║    /  \ ||  :  /   \_/   \_ |   [_ /  \ |/  \ ||   _] |  :  ||     T|     Tl___, |                ║"
	@sleep 0.02
	@echo "║    \    |l     \     \     ||     T\    |\    ||  T   l     ||     ||     ||     !                ║"
	@sleep 0.02
	@echo "║     \___j \__,_j\____j\____jl_____j \___j \___jl__j    \__,_jl_____jl_____jl____/                 ║"
	@sleep 0.02
	@echo "║                                                                                                   ║"
	@sleep 0.02
	@echo "╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝$(RESET)"

clean :
	@$(RM) $(OBJS)
	@echo "$(RED)╔════════════════════════════════════════════════════════════════════════════════════╗"
	@sleep 0.02
	@echo "║                                                                                    ║"
	@sleep 0.02
	@echo "║       __  _        ___   ____  ____   ____  ____    ____                           ║"
	@sleep 0.02
	@echo "║      /  ]| T      /  _] /    T|    \ l    j|    \  /    T                          ║"
	@sleep 0.02
	@echo "║     /  / | |     /  [_ Y  o  ||  _  Y |  T |  _  YY   __j                          ║"
	@sleep 0.02
	@echo "║    /  /  | l___ Y    _]|     ||  |  | |  | |  |  ||  T  |                          ║"
	@sleep 0.02
	@echo "║   /   \_ |     T|   [_ |  _  ||  |  | |  | |  |  ||  l_ |                          ║"
	@sleep 0.02
	@echo "║   \     ||     ||     T|  |  ||  |  | j  l |  |  ||     |                          ║"
	@sleep 0.02
	@echo "║    \____jl_____jl_____jl__j__jl__j__j|____jl__j__jl___,_j                          ║"
	@sleep 0.02
	@echo "║                                                                                    ║"
	@sleep 0.02
	@echo "║     ___   ____   ____    ___     __ ______      _____  ____  _        ___  _____   ║"
	@sleep 0.02
	@echo "║    /   \ |    \ |    |  /  _]   /  ]      T    |     |l    j| T      /  _]/ ___/   ║"
	@sleep 0.02
	@echo "║   Y     Y|  o  )l__  | /  [_   /  /|      |    |   __j |  T | |     /  [_(   \_    ║"
	@sleep 0.02
	@echo "║   |  O  ||     T__j  |Y    _] /  / l_j  l_j    |  l_   |  | | l___ Y    _]\__  T   ║"
	@sleep 0.02
	@echo "║   |     ||  O  /  |  ||   [_ /   \_  |  |      |   _]  |  | |     T|   [_ /  \ |   ║"
	@sleep 0.02
	@echo "║   l     !|     \     ||     T\     | |  |      |  T    j  l |     ||     T\    |   ║"
	@sleep 0.02
	@echo "║    \___/ l_____j\____jl_____j \____j l__j      l__j   |____jl_____jl_____j \___j   ║"
	@sleep 0.02
	@echo "║                                                                                    ║"
	@sleep 0.02
	@echo "╚════════════════════════════════════════════════════════════════════════════════════╝$(RESET)"

fclean :
	@$(RM) $(NAME) $(OBJS)
	@echo "$(RED)╔════════════════════════════════════════════════════════════════════════════════════════════╗"
	@sleep 0.02
	@echo "║                                                                                            ║"
	@sleep 0.02
	@echo "║    ____  __ __  ____  _       ___          __  _        ___   ____  ____     ___  ___      ║"
	@sleep 0.02
	@echo "║   |    \|  T  Tl    j| T     /   \        /  ]| T      /  _] /    T|    \   /  _]|   \     ║"
	@sleep 0.02
	@echo "║   |  o  )  l  | |  T | |    Y     Y      /  / | |     /  [_ Y  o  ||  _  Y /  [_ |    \    ║"
	@sleep 0.02
	@echo "║   |   _/|  _  | |  | | l___ |  O  |     /  /  | l___ Y    _]|     ||  |  |Y    _]|  D  Y   ║"
	@sleep 0.02
	@echo "║   |  |  |  |  | |  | |     T|     |    /   \_ |     T|   [_ |  _  ||  |  ||   [_ |     |   ║"
	@sleep 0.02
	@echo "║   |  |  |  |  | j  l |     |l     !    \     ||     ||     T|  |  ||  |  ||     T|     |   ║"
	@sleep 0.02
	@echo "║   l__j  l__j__j|____jl_____j \___/      \____jl_____jl_____jl__j__jl__j__jl_____jl_____j   ║"
	@sleep 0.02
	@echo "║                                                                                            ║"
	@sleep 0.02
	@echo "║     _____ __ __    __    __    ___  _____ _____ _____  __ __  _      _      __ __          ║"
	@sleep 0.02
	@echo "║    / ___/|  T  T  /  ]  /  ]  /  _]/ ___// ___/|     ||  T  T| T    | T    |  T  T         ║"
	@sleep 0.02
	@echo "║   (   \_ |  |  | /  /  /  /  /  [_(   \_(   \_ |   __j|  |  || |    | |    |  |  |         ║"
	@sleep 0.02
	@echo "║    \__  T|  |  |/  /  /  /  Y    _]\__  T\__  T|  l_  |  |  || l___ | l___ |  ~  |         ║"
	@sleep 0.02
	@echo "║    /  \ ||  :  /   \_/   \_ |   [_ /  \ |/  \ ||   _] |  :  ||     T|     Tl___, |         ║"
	@sleep 0.02
	@echo "║    \    |l     \     \     ||     T\    |\    ||  T   l     ||     ||     ||     !         ║"
	@sleep 0.02
	@echo "║     \___j \__,_j\____j\____jl_____j \___j \___jl__j    \__,_jl_____jl_____jl____/          ║"
	@sleep 0.02
	@echo "║                                                                                            ║"
	@sleep 0.02
	@echo "╚════════════════════════════════════════════════════════════════════════════════════════════╝$(RESET)"

re: fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJS)
