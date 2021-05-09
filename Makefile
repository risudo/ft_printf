NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_printf.c ft_printf_hex.c ft_printf_int.c ft_printf_str.c ft_printf_utils.c ft_input.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	ft_printf.h

%.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	:	$(OBJS)
			ar rcs ${NAME} ${OBJS}

all		:	${NAME}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re