NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror  -O3
LDFLAGS = -lmlx -framework OpenGL -framework AppKit -lm -O3
RM = rm -f

SRCS =	./mandatory/srcs/fractal.c \
		./mandatory/srcs/fractal_event.c \
		./mandatory/srcs/fractal_init.c \
		./mandatory/srcs/fractal_render.c \
		./mandatory/srcs/math_utils.c \
		./mandatory/srcs/lib/ft_atof.c \
		./mandatory/srcs/lib/ft_putchar.c \
		./mandatory/srcs/lib/ft_putstr.c \
		./mandatory/srcs/lib/ft_strcmp.c \
		./mandatory/srcs/lib/ft_strlen.c \

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