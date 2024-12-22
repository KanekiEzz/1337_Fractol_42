/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:09:29 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/22 09:28:34 by iezzam           ###   ########.fr       */
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

static void handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex point;
    t_complex c;
    int i;
    int color;

    i = 0;                                 
    point.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom);
    point.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom);

    mandel_vs_julia(&point, &c, fractal);

    while (i < fractal->max_iter)
    {
        point = sum_complex(square_complex(point), c);
        if ((point.x * point.x) + (point.y * point.y) > fractal->escape_value)
        {
            color = map(i, BLACK, 0x0F030507, 0, 256);
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
