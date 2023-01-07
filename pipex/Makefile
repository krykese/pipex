NAME := pipex.a
SOFT_NAME := pipex
LIBFT := LIBFT/libft.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g3

SRC = main.c \
	find_path.c \
	process.c \
	utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ := $(SRC:.c=.o)

all: ${LIBFT} $(NAME) $(SOFT_NAME)

${LIBFT} :
	${MAKE} all -C LIBFT
	cp ${LIBFT} ${NAME}

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(SOFT_NAME):
	$(CC) $(CFLAGS) -o $(SOFT_NAME) $(NAME) $^

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	${MAKE} clean -C LIBFT
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	${MAKE} fclean -C LIBFT
	rm -f $(NAME)
	rm -f $(SOFT_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
