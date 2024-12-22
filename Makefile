NAME = fractol
NAMEB = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror  -O3
LDFLAGS = -lmlx -framework OpenGL -framework AppKit -lm -O3
RM = rm -f
AR = ar -rc

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

SRCSB = ./bouns/srcs/fractal.c \
		./bouns/srcs/fractal_event.c \
		./bouns/srcs/fractal_init.c \
		./bouns/srcs/fractal_render.c \
		./bouns/srcs/math_utils.c \
		./bouns/srcs/lib/ft_atof.c \
		./bouns/srcs/lib/ft_putchar.c \
		./bouns/srcs/lib/ft_putstr.c \
		./bouns/srcs/lib/ft_strcmp.c \
		./bouns/srcs/lib/ft_strlen.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS)


$(NAMEB): $(OBJSB)
	$(CC)  $(OBJSB) -o $(NAME) $(LDFLAGS)

%.o: %.c ./includes/fractal.h
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAMEB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean