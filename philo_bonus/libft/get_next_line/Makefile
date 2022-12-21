NAME		=	libgnl.a

SRCS		=	get_next_line.c get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

GNL			=	gnl

all:		$(NAME)

.c.o :	
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -rf *.d
			rm -rf *.o
			
fclean:		clean
			rm -rf *.a

re:			fclean all

.PHONY:		all clean fclean re