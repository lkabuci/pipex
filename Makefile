all:
	make -C bonus
	make clean -C bonus

bonus:
	make -C bonus

clean:
	make clean -C bonus
	make clean -C bonus

fclean: clean
	make fclean -C bonus
	make fclean -C bonus

.PHONY: bonus all clean fclean