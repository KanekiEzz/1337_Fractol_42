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
		./bouns/srcs/lib/print_usag.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS)


$(NAMEB): $(OBJSB)
	$(CC)  $(OBJSB) -o $(NAMEB) $(LDFLAGS)
	@echo "\033[1;34m\
        ##    ##    ###    ##    ## ######## ##    ## #### \\n\
        ##   ##    ## ##   ###   ## ##       ##   ##   ##  \\n\
        ##  ##    ##   ##  ####  ## ##       ##  ##    ##  \\n\
        #####    ##     ## ## ## ## ######   #####     ##  \\n\
        ##  ##   ######### ##  #### ##       ##  ##    ##  \\n\
        ##   ##  ##     ## ##   ### ##       ##   ##   ##  \\n\
        ##    ## ##     ## ##    ## ######## ##    ## #### \\033[0m\\n\
		\033[1;32mUsage:\033[0m\\n\
		\033[1;33m\\n\
			1:     ./fractol or ./fractol_bonus julia <real> <imaginary>\\n\
			or\\n\
			2:     ./fractol or ./fractol_bonus mandelbrot\\n\
			or\\n\
			3:     ./fractol or ./fractol_bonus burningship\\n\
			or\\n\
			4:     ./fractol or ./fractol_bonus tricorn\\n\
			or\\n\
			5:     ./fractol or ./fractol_bonus celtic\\033[0m\\n"

%.o: %.c ./includes/fractal.h
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAMEB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all

.PHONY: clean print_usage
print_usage:
	@echo "\033[1;34m\
        ##    ##    ###    ##    ## ######## ##    ## #### \\n\
        ##   ##    ## ##   ###   ## ##       ##   ##   ##  \\n\
        ##  ##    ##   ##  ####  ## ##       ##  ##    ##  \\n\
        #####    ##     ## ## ## ## ######   #####     ##  \\n\
        ##  ##   ######### ##  #### ##       ##  ##    ##  \\n\
        ##   ##  ##     ## ##   ### ##       ##   ##   ##  \\n\
        ##    ## ##     ## ##    ## ######## ##    ## #### \\033[0m\\n\
		\033[1;32mUsage:\033[0m\\n\
		\033[1;33m\\n\
			1:     ./fractol or ./fractol_bonus julia <real> <imaginary>\\n\
			or\\n\
			2:     ./fractol or ./fractol_bonus mandelbrot\\n\
			or\\n\
			3:     ./fractol or ./fractol_bonus burningship\\n\
			or\\n\
			4:     ./fractol or ./fractol_bonus tricorn\\n\
			or\\n\
			5:     ./fractol or ./fractol_bonus celtic\\033[0m\\n"