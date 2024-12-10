NAME = fractal
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
RM = rm -f



SRCS =	./srcs/fractal.c \
		./srcs/string_utils.c \
		./srcs/fractal_init.c \
		./srcs/fractal_render.c \
		./srcs/fractal_event.c \
		./srcs/math_utils.c \
		./srcs/lib/ft_strlen.c \
		./srcs/lib/ft_strcmp.c \
		./srcs/lib/ft_atof.c \
		./srcs/lib/ft_putchar.c \
		./srcs/lib/ft_putstr.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c ./includes/fractal.h
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean