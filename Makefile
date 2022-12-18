SRCS		=   ./philo/srcs/initialization.c \
				./philo/srcs/philo.c \
				./philo/srcs/threading.c \
				./philo/srcs/state.c \
				./philo/srcs/death.c \
				./philo/srcs/time.c \
				./philo/srcs/mutex.c \
				./philo/srcs/print.c \
				./philo/srcs/syscall.c \
				./philo/srcs/routine.c \


SRCS_BONUS	= 	./philo_bonus/srcs/initialization.c \
				./philo_bonus/srcs/philo.c \
				./philo_bonus/srcs/threading.c \
				./philo_bonus/srcs/state.c \
				./philo_bonus/srcs/death.c \
				./philo_bonus/srcs/time.c \
				./philo_bonus/srcs/mutex.c \
				./philo_bonus/srcs/print.c \
				./philo_bonus/srcs/syscall.c \
				./philo_bonus/srcs/routine.c \

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

DEPS_BONUS	= $(SRCS_BONUS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

PHILO		=	philosopher

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

bonus:		$(OBJS_BONUS)
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS_BONUS} -g3 -L./lib -lft -lpthread -lprintf -lgnl -o $(PHILO)

clean:
			rm -rf $(OBJS)
			rm -rf $(OBJS_BONUS)
			rm -rf $(DEPS)
			rm -rf $(DEPS_BONUS)
			
fclean:		clean
			make -C ./libft fclean
			make -C ./libft/ft_printf fclean
			make -C ./libft/get_next_line fclean
			rm -rf $(PHILO) ./lib/*.a

re:			fclean all

-include : $(DEPS) $(DEPS_BONUS)

.PHONY:		all clean fclean re