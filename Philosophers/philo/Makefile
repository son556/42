# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-fsanitize=address -g
RM			=	rm -f

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo

HEADER		=	./includes/

SRC_LIST	=	./srcs/philo.c \
				./srcs/utils/print_philo.c \
				./srcs/utils/ft_strcmp.c \
				./srcs/utils/ft_atoi.c \
				./srcs/utils/calc_time.c \
				./srcs/utils/time_check.c \
				./srcs/utils/newsleep.c \
				./srcs/set/set_init.c \
				./srcs/valid_check/input_check.c \
				./srcs/valid_check/check_digit.c \
				./srcs/thread/init_thread.c \
				./srcs/thread/thread_philo.c \
				./srcs/thread/thread_philo_one.c \
				./srcs/mutex/init_mutex.c \
				./srcs/philo_status/check_die.c \
				./srcs/philo_status/take_forks.c \
				./srcs/philo_status/takeoff_forks.c \
				./srcs/philo_status/take_sleep.c \
				./srcs/philo_status/take_eat.c \
				./srcs/philo_status/take_think.c \
				./srcs/philo_status/monitoring.c \

OBJ			=	$(SRC_LIST:.c=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o			:	%.c
				@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@echo $(GREEN) "Source files are compiled!\n" $(EOC)
				@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
				@$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJ)
				@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@$(RM) $(OBJ)
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY		:	fclean
fclean		:	clean
				@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
				@$(RM) $(NAME)
				@echo $(RED) "$(NAME) is removed!\n" $(EOC)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette