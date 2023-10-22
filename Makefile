NAME_BASIC = so_long
NAME_BONUS = so_long_bonus

RM = rm -rf

all:
	@make -C $(NAME_BASIC) all

bonus:
	@make -C $(NAME_BONUS) all

clean:
	@make -C $(NAME_BASIC) clean

bclean:
	@make -C $(NAME_BONUS) clean

fclean:
	@make -C $(NAME_BASIC) fclean

bfclean:
	@make -C $(NAME_BONUS) fclean

re: fclean all
bre: bfclean bonus

.PHONY: all clean bclean fclean bfclean re bre bonus