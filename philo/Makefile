SRCS		=   ./srcs/initialization.c \
				./srcs/philo.c \
				./srcs/threading.c \
				./srcs/state.c \
				./srcs/death.c \
				./srcs/time.c \
				./srcs/mutex.c \
				./srcs/print.c \
				./srcs/syscall.c \
				./srcs/routine.c \
				./srcs/lib.c \

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

PHILO		=	philo

all:		$(PHILO)

.c.o :	
			$(CC) -g3 $(CFLAGS) -c $< -o $@

$(PHILO):	${OBJS}
			$(CC) $(CFLAGS) ${OBJS} -g3 -lpthread -o $(PHILO)


clean:
			rm -rf $(OBJS)
			rm -rf $(DEPS)
			
fclean:		clean
			rm -rf $(PHILO)

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re