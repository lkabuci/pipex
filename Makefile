CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror -g

NAME	=	pipex
HEADER	=	pipex.h
SRCS	=	main.c \
			parse.c \
			utils.c \
			split.c \
			pipex_utils.c \
			utils_print.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME) $(HEADER)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) a.out

re: fclean all