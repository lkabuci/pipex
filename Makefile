NAME	=	pipex

all:
	@make -C libft
	@make -C manda

bonus:
	@make -C libft
	@make -C bonus

clean:
	@rm -rf bin/
	@echo Cleaned

fclean: clean
	@rm -rf $(NAME) libft.a a.out ret
	@echo Erased

re:	fclean all
	@echo Recompiled.

.PHONY: bonus