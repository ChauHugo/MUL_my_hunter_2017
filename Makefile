##
## EPITECH PROJECT, 2017
## my_hunter
## File description:
## my_hunter Makefile
##

NAME 					= my_hunter

LIB_DIR					= ./lib

INC_DIR					= ./include

FLAGS					= -Wall -Wextra

LIB_FLAG				= -l c_graph_prog -L$(LIB_DIR) -lmy

SRC						= src/main.c 					\
						  src/assets_utils.c 			\
						  src/utils.c 					\
						  src/my_hunter.c 				\
						  src/events.c 					\
						  src/mouse_events.c 			\
						  src/score.c 					\
						  src/animation.c 				\
						  src/anim_utils.c 				\
						  src/player.c

CFLAGS					= $(FLAGS) $(LIB_FLAG) -I$(INC_DIR)

all: 					$(NAME) msg

$(NAME):				library
						gcc -o $(NAME) $(SRC) $(CFLAGS)

library:				
						make -C $(LIB_DIR)

clean:
						rm -f *.o

fclean:					clean
						rm -f $(NAME)
						make fclean -C $(LIB_DIR)

re:						fclean all

msg:
						@echo "==> SUCCESSFULLY COMPILED"
