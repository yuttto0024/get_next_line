NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

BUFFER_SIZE ?= 42
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)

SRCS = \
		get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re