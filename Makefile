NAME	=	pipex

all:
	@make -C libft
	@make -C manda

bonus:
	@make -C libft
	@make -C bonus

clean:
	rm -rf bin/

fclean: clean
	rm -rf $(NAME) libft.a

re:	fclean all

.PHONY: bonus