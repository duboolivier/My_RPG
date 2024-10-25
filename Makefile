##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## minishell 1
##

SRC	=	src/main.c	\
		src/raycasting.c	\
		src/setup.c	\
		src/events.c \
		src/enemies.c \
		src/floor_casting.c \
		src/sprite_casting.c \
		src/movement.c	\
		src/weapon.c	\
		src/npc_dialog.c	\
		src/health.c	\
		src/destroy.c	\
		src/options.c	\
		src/pause.c	\
		src/save.c	\
		src/ending.c	\
		src/level.c	\
		src/splash_screen.c	\
		src/error_handling/file_check.c	\
		src/dash_h.c	\
		src/menu/init_button.c \
		src/menu/main_menu.c \
		src/error_handling/env_error.c \
		src/menu/music.c \
		src/menu/anim_buttons.c \
		src/inventory.c \
		src/init_button_inventory.c 	\
		src/main_loop.c 	\
		src/menu/button_status.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra -l csfml-graphics -l csfml-window \
			-l csfml-system -l csfml-audio -lm -Ofast -I./includes

CPPFLAGS = 	-I./include

TESTS_LIBS	=	--coverage -lcriterion

TESTS_NAME	=	unit_tests

TESTS_SRC	=	a

CC	=	gcc

all: $(NAME)

$(NAME):	$(OBJ)	$(LIBMY)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

$(LIBMY):
		make -C lib

debug:	CFLAGS += -g3 -fsanitize=address
debug:	$(NAME)

tests:	$(TESTS_NAME)

$(TESTS_NAME):	$(LIBMY)
		$(CC) -o $(TESTS_NAME) $(TESTS_SRC) $(TESTS_LIBS) $(LDFLAGS) $(LDLIBS)

clean:
		rm -f $(OBJ)
		find . -name "*~" -delete
		find . -name "#*#" -delete
		find . -name "*.o" -delete
		find . -name "libmy.a" -delete

fclean:		clean
		rm -f $(NAME)

re:		fclean all

auteur:
		echo $(USER) > auteur

.PHONY:-all clean fclean re tests
