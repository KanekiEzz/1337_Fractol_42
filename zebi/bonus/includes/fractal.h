/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/10 01:13:02 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H 
#define FRACTOL_H

//+++++++++start forbidden++++++++
#include <string.h>
#include <stdio.h>
#include <math.h>

//+++++++++end forbidden++++++++

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <mlx.h>
// #include <X11/keysym.h>
// #include "../minilibx_opengl_20191021/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

/*
	we use a square to
	keep the render math simple
*/
#define WIDTH 800
#define HEIGHT 800

enum				e_MOUSE_CODES
{
	ZOOM_OUT = 4,
	ZOOM_IN = 5,
};

enum				e_KEY_CODES
{
	ESC = 53,
	ENTER = 36,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	SPACE = 49,
	ADD_COLOR =  24,
	MINUS_COLOR =  27,
};


/*
	Image
	This is basically a pixels buffer
	values from from mlx_get_data_addr()
*/
typedef struct s_img
{
	void	*img_ptr; // pointer to image stuct
	char	*pixels_ptr; // points to the actual pixels
	int		bpp;
	int		endian;
	int		line_length;
} t_imag;


/*
	Fractol id
	MLX stuff
	Image
	Hooks values
*/
typedef struct s_fractal
{
	char *name;
	//MLX
	void *mlx_connection;  // mlx_init()
	void *mlx_window; // mlx_new_window()
	// image
	t_imag img;

	// Hokks member variables
	double escape_value; //hypotenuse
	int max_iter; // max iterations | value tight with the image quality and rendering speed

	// shift
	double	shift_x;
	double	shift_y;


	double	julia_x;
	double	julia_y;
	
	double zoom;



	int				random_flag;
	double			random_color;
} t_fractal;


/*
*	complex value
*/

typedef struct	s_complex
{
	double x; // real
	double y; // imag
}				t_complex;



// ./src/
void fractal_init(t_fractal *fractal);		/* init fractal */
void fractal_render(t_fractal *fractal);	/*render  fractal*/
int key_handler(int keycode, t_fractal *fractal);	/*=====hooks_event=====*/
int close_handler(t_fractal *fractal); /*=====clean_up close windows=====*/
int mouse_handler(int button, int x, int y, t_fractal *fractal); /*=====mouse handler=====*/
int	julia_track(int x, int y, t_fractal *fractal);	/*=====change dynamically in mouse=====*/

void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
void my_pixel_put(int x, int y, t_imag *img, int color);

// ./scs ++++++++++++math++++++++++++
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex a, t_complex b);
t_complex square_complex(t_complex a);

// ./src/lib/..
void	ft_putstr(char *s);
void	ft_putchar(char c);
int	ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *str);
size_t	ft_strlen(const char *s);


double	atodbl(char *s);

#endif