NAME		=	libprintf.a

SRCS 		=	ft_printf.c \
				ft_putchar.c \
				ft_atoi.c \
				ft_strlen.c \
				ft_print_zero.c \
				ft_print_plus.c \
				ft_print_space.c \
				ft_print_minus.c \
				ft_print_hash.c \
				ft_print_char.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_checker.c \
				ft_putnb_uns.c \
				ft_putnbr.c \
				ft_putnbr_base_hexa.c \
				ft_putstr_fd.c \
				ft_write_add.c \

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	-I ./

BONUS		=	ft_printf.c \
				ft_putchar.c \
				ft_print_no_format.c \
				ft_strlen.c \
				ft_print_zero.c \
				ft_print_plus.c \
				ft_print_space.c \
				ft_print_minus.c \
				ft_print_hash.c \
				ft_print_char.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_checker.c \
				ft_putnb_uns.c \
				ft_putnbr.c \
				ft_putnbr_base_hexa.c \
				ft_putstr_fd.c \
				ft_write_add.c \

CC			=	gcc -g3

CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

bonus : ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
