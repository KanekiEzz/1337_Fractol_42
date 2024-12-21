/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaneki <kaneki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/21 02:29:07 by kaneki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H 
#define FRACTOL_H

//+++++++++start forbidden++++++++
#include <string.h>
#include <stdio.h>
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


/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
} t_imag;

typedef struct s_fractal
{
	char *name;
	void *mlx_connection;
	void *mlx_window;
	t_imag img;

	double escape_value;
	int max_iter;
	
	double	julia_x;
	double	julia_y;
	
	double zoom;
} t_fractal;

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;





// ./src/
void fractal_init(t_fractal *fractal);		/* init fractal */
void fractal_render(t_fractal *fractal);	/*render  fractal*/
int key_handler(int keycode, t_fractal *fractal);	/*=====hooks_event=====*/
int close_handler(t_fractal *fractal); /*=====clean_up close windows=====*/
int mouse_handler(int button, int x, int y, t_fractal *fractal); /*=====mouse handler=====*/
int	julia_track(int x, int y, t_fractal *fractal);	/*=====change dynamically in mouse=====*/

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