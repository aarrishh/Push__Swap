NAME = push_swap
INC_DIR = includes
SRC_DIR = src
SRC_DIR_BONUS = src_bonus
BON_DIR = bonus
BONUS = checker

SRC =  $(SRC_DIR)/butterfly.c  $(SRC_DIR)/butterfly1.c  $(SRC_DIR)/functions.c \
		$(SRC_DIR)/functions1.c  $(SRC_DIR)/main.c  $(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations1.c  $(SRC_DIR)/sorting.c  $(SRC_DIR)/split.c \
		$(SRC_DIR)/validation.c  $(SRC_DIR)/sort.c

BSRC = $(SRC_DIR_BONUS)/get_next_line.c  $(SRC_DIR_BONUS)/get_next_line_utils.c \
		$(SRC_DIR_BONUS)/butterfly.c  $(SRC_DIR_BONUS)/butterfly1.c  $(SRC_DIR_BONUS)/functions.c \
		$(SRC_DIR_BONUS)/functions1.c  $(SRC_DIR_BONUS)/bonus.c $(SRC_DIR_BONUS)/operations.c \
		$(SRC_DIR_BONUS)/operations1.c  $(SRC_DIR_BONUS)/sorting.c  $(SRC_DIR_BONUS)/split.c \
		$(SRC_DIR_BONUS)/validation.c $(SRC_DIR_BONUS)/sort.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

RM = rm -f

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

# test_my: $(NAME)
# 	$(eval ARG = $(shell seq 0 2000000 | shuf | head -n 100))
# 	@valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
# 	@echo -n "Instructions: "
# 	@valgrind ./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re bonus
