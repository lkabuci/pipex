CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror -g

NAME	=	pipex
HEADER	=	pipex.h
SRCS	=	pipex.c \
			parse.c \
			split.c \
			error.c \
			utils.c \
			utils2.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME) $(HEADER)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) a.out outfile infile

re: fclean all