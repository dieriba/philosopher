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

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

PHILO		=	philo

all:		$(PHILO)

.c.o :	
			$(CC) -g3 $(CFLAGS) -c $< -o $@

$(PHILO):	${OBJS}
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS} -g3 -L./lib -lft -lpthread -lprintf -lgnl -o $(PHILO)


clean:
			rm -rf $(OBJS)
			rm -rf $(DEPS)
			
fclean:		clean
			make -C ./libft fclean
			make -C ./libft/ft_printf fclean
			make -C ./libft/get_next_line fclean
			rm -rf $(PHILO) ./lib/*.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re