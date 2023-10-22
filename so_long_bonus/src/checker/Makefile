NAME = checker.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = check_game_logic.c \
	checker.c \
	create_map.c \
	free_map.c \
	is_ber.c \
	is_map_rectangle.c 


OBJS = check_game_logic.o \
	checker.o \
	create_map.o \
	free_map.o \
	is_ber.o \
	is_map_rectangle.o 

all : $(NAME)

$(NAME) :
		@$(CC) $(FLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)
		@printf "\033[0;32mchecker Make yapildi\n\033[0m"

clean:
	@rm -f  $(OBJS)
	@printf "\033[0;33mchecker clean yapildi\n\033[0m"

fclean:
	@rm -f  $(OBJS)
	@printf "\033[0;33mchecker fclean yapildi\n\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re