CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g -I

LIBFT		=	../libft.a
NAME		=	pipex

SRCS		=	main_bonus.c \
				ft_checks.c \
				utils1_bonus.c \
				utils2_bonus.c \
				here_doc_bonus.c \
				pipeline_bonus.c \
				pipeline_exec_bonus.c

OBJ_DIR		=	../bin/
OBJCTS		=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC_DIR		=	../includes/
INCLUDES	=	$(addprefix $(INC_DIR),pipex_bonus.h)

bonus:	$(NAME) $(INCLUDES)

$(NAME):	$(OBJCTS)
	@$(CC) $(CFLAGS) $(INC_DIR) $^ $(LIBFT) -o ../$@
	@echo "bonus pipex is ready."

$(OBJ_DIR)%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@