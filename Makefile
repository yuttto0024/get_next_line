Name = gnl_tester

CC = CC
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

BUFFER_SIZE ?= 42
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)

SRCS = \
		get_next_line.c \
		get_next_line_utils.c \

MAIN_SRC = main.c

OBJS = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re