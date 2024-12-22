/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/21 03:32:29 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H 
#define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH 800
#define HEIGHT 800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)

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


#endif