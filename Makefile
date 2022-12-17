SRCS		=  ./mandatory/srcs/initialization.c \
				./mandatory/srcs/philo.c \
				./mandatory/srcs/threading.c \
				./mandatory/srcs/state.c \
				./mandatory/srcs/death.c \
				./mandatory/srcs/time.c \
				./mandatory/srcs/mutex.c
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
			rm -rf ./mandatory/srcs/$(OBJS)
			rm -rf ./mandatory/srcs/$(DEPS)
			
fclean:		clean
			make -C ./libft fclean
			make -C ./libft/ft_printf fclean
			make -C ./libft/get_next_line fclean
			rm -rf $(PHILO) ./lib/*.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re