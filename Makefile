

NAME		:= gnl.a

SRC			:= get_next_line.c	\
			get_next_line_utils.c

SRC_BONUS	:= get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJ			:= $(SRC:.c=.o)
BONUS_OBJ	:= $(SRC:.c=.o)
CFLAGS 		+= -Wall -Werror -Wextra -I ./

$(NAME): $(OBJ)
         gcc -o $(NAME) $(OBJ)


