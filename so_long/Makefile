NAME			=	so_long

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

MAIN			=	./src/main/main.c

SRC				=	./src/checker/checker.c \
					./src/checker/create_map.c \
					./src/checker/error_message.c \
					./src/checker/game_logic.c \
					./src/checker/is_ber.c \
					./src/checker/is_rectangle.c \
					./src/main/so_long.c \
					./src/movement/finish_game.c \
					./src/movement/get_size_of_coin.c \
					./src/movement/move.c \
					./src/movement/render_next_frame.c \
					./src/movement/set_all_sprites.c \
					./src/movement/set_location_player.c \
					./src/movement/set_window.c

LIBFT_PATH		=	../resources/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	../resources/minilibx

all:				$(NAME)

$(NAME):			$(LIBFT) mlx
					$(CC) $(CFLAGS) $(MAIN) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) all

mlx:
					make -C $(MINILIBX_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(MINILIBX_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft