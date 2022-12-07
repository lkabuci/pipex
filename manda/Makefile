CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g -I

LIBFT		=	../libft.a
NAME		=	pipex

SRCS		=	main.c parse.c utils.c

OBJ_DIR		=	../bin/
OBJCTS		=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR		=	../includes/
INCLUDES	=	$(addprefix $(INC_DIR),pipex.h)

all:	$(NAME) $(INCLUDES)

$(NAME):	$(OBJCTS)
	@$(CC) $(CFLAGS) $(INC_DIR) $^ $(LIBFT) -o ../$@
	@echo "madatory pipex is ready."

$(OBJ_DIR)%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@