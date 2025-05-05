NAME = fractol
NAMEB = fractol_bonus

CC = cc
CFLAGS =  -O3 -lm
LDFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd

RM = rm -f

SRCS = \
	./mandatory/srcs/fractal.c \
	./mandatory/srcs/fractal_event.c \
	./mandatory/srcs/fractal_init.c \
	./mandatory/srcs/fractal_render.c \
	./mandatory/srcs/math_utils.c \
	./mandatory/srcs/lib/ft_atof.c \
	./mandatory/srcs/lib/ft_putchar.c \
	./mandatory/srcs/lib/ft_putstr.c \
	./mandatory/srcs/lib/ft_strcmp.c \
	./mandatory/srcs/lib/ft_strlen.c \

SRCSB = \
		./bouns/srcs/fractal.c \
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

# Default rule
all: minilibx-linux $(NAME) force_usage


bonus: minilibx-linux $(NAMEB) force_usage

force_usage:
	@$(MAKE) print_usage
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@$(MAKE) print_usage

$(NAMEB): $(OBJSB)
	$(CC) $(OBJSB) -o $(NAMEB) $(LDFLAGS)
	@$(MAKE) print_usage

# Object rules
./mandatory/%.o: ./mandatory/%.c ./mandatory/includes/fractal.h
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/%.o: ./bonus/%.c ./bonus/includes/fractal.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(NAMEB) 
	@rm -rf minilibx-linux

re: fclean all

# Clone & build MiniLibX safely
minilibx-linux:
	@if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	@$(MAKE) -C minilibx-linux

# Print fractol usage
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

.PHONY: all bonus clean fclean re print_usage minilibx-linux
