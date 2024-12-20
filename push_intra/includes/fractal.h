/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/10 04:25:58 by iezzam           ###   ########.fr       */
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


#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

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
};


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
int mouse_handler(int button, t_fractal *fractal); /*=====mouse handler=====*/
int	julia_track(int x, int y, t_fractal *fractal);	/*=====change dynamically in mouse=====*/

// void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
// void my_pixel_put(int x, int y, t_imag *img, int color);





// ./scs ++++++++++++math++++++++++++
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