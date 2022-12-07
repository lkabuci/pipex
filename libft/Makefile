# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relkabou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 16:08:09 by relkabou          #+#    #+#              #
#    Updated: 2022/10/19 15:25:10 by relkabou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I
RM			=	rm -rf
AR			=	ar rcs

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME		=	../libft.a
SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_calloc.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_fprintf.c \
				ft_fprintf_utils.c \
				get_next_line.c \

OBJCTS_DIR	=	../bin/
OBJCTS		= $(addprefix $(OBJCTS_DIR),$(SRCS:.c=.o))

INC_DIR		=	../includes/
INCLUDES	=	$(addprefix $(INC_DIR),libft.h)

all: $(NAME) $(INCLUDES)

$(NAME):	$(OBJCTS)
	@$(AR) $(NAME) $(OBJCTS)
	@echo "libft compiled."

$(OBJCTS_DIR)%.o: %.c
	@mkdir -p $(OBJCTS_DIR)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

fclean:
	$(RM) $(NAME)

.PHONY: all

