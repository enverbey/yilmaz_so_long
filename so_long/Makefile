NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC				=	./src/main/main.c \
					./src/main/so_long.c \
					./src/main/get_size_of_coin.c \
					./src/main/set_location_player.c \
					./src/main/set_all_sprites.c \
					./src/main/finish_game.c \
					./src/main/move.c \
					./src/main/set_window.c

OBJS			=	main.o \
					so_long.o \
					get_size_of_coin.o \
					set_location_player.o \
					set_all_sprites.o \
					finish_game.o \
					move.o \
					set_window.o

CHECKER_PATH	=	./src/checker
CHECKER			=	$(CHECKER_PATH)/checker.a

LIBFT_PATH		=	./src/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./src/minilibx

all : $(NAME)

$(NAME):			$(LIBFT) $(CHECKER) mlx
					@$(CC) $(FLAGS) $(SRC) $(LIBFT) $(CHECKER) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx -o $(NAME)

$(LIBFT):
		@make -C $(LIBFT_PATH) all

$(CHECKER):
		@make -C $(CHECKER_PATH) all

mlx:
		@make -C $(MINILIBX_PATH) all

print:
		@printf "\033[0;32mSo Long Make yapildi\n\033[0m"

clean:
	@rm -f  $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(CHECKER_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@printf "\033[0;33mSo Long clean yapildi\n\033[0m"

fclean:
	@rm -f  $(OBJS)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(CHECKER_PATH) fclean
	@printf "\033[0;33mSo Long fclean yapildi\n\033[0m"
	@make -C $(MINILIBX_PATH) clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re