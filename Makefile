CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
AR = ar rcs
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
NAME = push_swap
SRC = main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re