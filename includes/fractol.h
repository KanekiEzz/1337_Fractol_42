/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/08 15:15:11 by iezzam           ###   ########.fr       */
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
#include "../minilibx-linux/mlx.h"


/*
	we use a square to
	keep the render math simple
*/
#define WIDTH 800
#define HEIGHT 800



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

	// Hokks member variable
} t_fractal;


typedef struct	s_complex
{
	double real; // x
	double im; // y
}				t_complex;

// ./src/
void fractal_init(t_fractal *fractal);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);


// ./src/lib/..
void	ft_putstr(char *s);
void	ft_putchar(char c);
int	ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *str);
size_t	ft_strlen(const char *s);




#endif