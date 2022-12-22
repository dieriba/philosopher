SRCS_BONUS	= 	./srcs/initialization.c \
				./srcs/philo.c \
				./srcs/forking.c \
				./srcs/time.c \
				./srcs/semaphore.c \
				./srcs/semaphore_utils.c \
				./srcs/print.c \
				./srcs/syscall.c \
				./srcs/exit.c \
				./srcs/threading.c \
				./srcs/death.c \
				./srcs/routine.c \
				./srcs/state.c \
				./srcs/lib.c \
				./srcs/lib_utils.c \
				./srcs/lib_utils2.c \


OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

DEPS_BONUS	= $(SRCS_BONUS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

PHILO		=	philo

all:		$(PHILO)

bonus:		all

.c.o :	
			$(CC) -g3 $(CFLAGS) -c $< -o $@
			
$(PHILO):	${OBJS_BONUS}
			$(CC) $(CFLAGS) ${OBJS_BONUS} -g3 -lpthread -o $(PHILO)


clean:
			rm -rf $(OBJS_BONUS)
			rm -rf $(DEPS_BONUS)
			
fclean:		clean
			rm -rf $(PHILO)

re:			fclean all

-include : $(DEPS_BONUS)

.PHONY:		all clean fclean re bonus