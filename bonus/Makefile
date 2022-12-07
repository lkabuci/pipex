CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror -g

NAME	=	pipex
HEADER	=	pipex_bonus.h
SRCS	=	main_bonus.c \
			parse_bonus.c \
			split_bonus.c \
			error_bonus.c \
			utils_bonus.c \
			utils2_bonus.c \
			pipes_bonus.c \
			lst_manip_bonus.c \
			here_doc_bonus.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME) $(HEADER)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o ../$(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) a.out outfile infile

re: fclean all