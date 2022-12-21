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
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS_BONUS} -g3 -L./lib -lft -lpthread -lprintf -lgnl -o $(PHILO)


clean:
			rm -rf $(OBJS_BONUS)
			rm -rf $(DEPS_BONUS)
			
fclean:		clean
			make -C ./libft fclean
			make -C ./libft/ft_printf fclean
			make -C ./libft/get_next_line fclean
			rm -rf $(PHILO) ./lib/*.a

re:			fclean all

-include : $(DEPS_BONUS)

.PHONY:		all clean fclean re bonus