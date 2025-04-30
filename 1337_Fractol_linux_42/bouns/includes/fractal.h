/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaneki <kaneki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2025/03/30 14:12:44 by kaneki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../minilibx-linux/mlx.h"

# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}	t_imag;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_imag	img;

	double	escape_value;
	int		max_iter;

	double	shift_x;
	double	shift_y;

	double	julia_x;
	double	julia_y;

	double	zoom;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

double		map(double point, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	conjugate(t_complex z);
t_complex	square_complex(t_complex a);
t_complex	absolute(t_complex z);

void		ft_putstr(char *s);
void		ft_putchar(char c);
int			ft_strcmp(const char *s1, const char *s2);
double		ft_atof(const char *str);
size_t		ft_strlen(const char *s);
void		print_usag(void);

#endif