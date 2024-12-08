/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:24 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/08 22:40:41 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 *   Put a pixel on the image with the color of the point
 *   Put a pixel in  my image buffer
 */
static void my_pixel_put(int x, int y, t_imag *img, int color)
{
    int offset;

    offset = (y * img->line_length) + (x * (img->bpp / 8));

    *(unsigned int *)(img->pixels_ptr + offset) = color;
}
static void handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    // pixel coordinate x & y scaled to fit mandel needs
    c.x = map(x, -2, +2, 0, WIDTH);
    c.y = map(y, +2, -2, 0, HEIGHT);

    // How many times you want to iterate z^2 + c
    // to check if the point escaped?
    // Max iterations:
    while (i < fractal->max_iter)
    {
        // actual z^2 + c
        //  z = z^2 + c ;
        z = sum_complex(square_complex(z), c);

        // is the value escaped ???
        // if hypotenuse > 2 i assume the point has escaped
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractal->max_iter);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
        // we are in MANDELBROT given the iteration made
        my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
    }
}

// X(-2, 0.5)
// Y(-1, 1)

/*
 *      ------800------   -2-----------+2
 *      |             |   |             |
 *      |             |   |             |
 *      |             |   |             |
 *      |             |   |             |
 *      ------800------   ---------------
 *      Z = Z^2 + C
 *      Z = initially is (0, 0)
 *      c is the actual point on the complex plane
 */

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handel_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr,
                            0, 0);
}