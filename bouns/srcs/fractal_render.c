/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:24 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/24 13:57:18 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static void my_pixel_put(int x, int y, t_imag *img, int color)
{
    int offset;

    offset = (y * img->line_length) + (x * (img->bpp / 8));

    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}
t_complex	absolute(t_complex z)
{
	t_complex	res;

	res.x = z.x;
	res.y = z.y;
	if (res.x < 0)
		res.x = -res.x;
	if (res.y < 0)
		res.y = -res.y;
	return (res);
}
t_complex conjugate(t_complex z)
{
    t_complex result;
    result.x = z.x;
    result.y = -z.y;
    return result;
}
static void handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;                                 
    z.x = (map(x, -2, +2, WIDTH) * fractal->zoom)+ fractal->shift_x ;
    z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom)+ fractal->shift_y;

	mandel_vs_julia(&z, &c, fractal);

    while (i < fractal->max_iter)
    {	
		if (!ft_strcmp(fractal->name, "burningship"))
			z = sum_complex(square_complex(absolute(z)), c);
		if (!ft_strcmp(fractal->name, "tricorn"))
			z = sum_complex(square_complex(conjugate(z)), c);
		if (!ft_strcmp(fractal->name, "celtic"))
		{
    		t_complex squared = square_complex(z);
    		z.x = fabs(squared.x - squared.x);
    		z.y = 2 * squared.y * squared.y;
    		z = sum_complex(z, c);
		}
		else
			z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, 0x0F030507, 256);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
        my_pixel_put(x, y, &fractal->img, BLACK);
    }
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handel_pixel(x, y, fractal);
			x++;
		}
		y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr,
                            0, 0);
}