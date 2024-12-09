/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:24 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/09 14:44:28 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

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


/*
 * EASY TOGGLE mandel & julia
*/
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
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;

    // pixel coordinate x & y scaled to fit mandel needs
                                        
    z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom)+ fractal->shift_x ; // ta7akoum f mouse in shift->x
    z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom)+ fractal->shift_y;  // ta7akoum f mouse in shift->y

    mandel_vs_julia(&z, &c, fractal);
    
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
            color = map(i, BLACK, WHITE, 0, 42);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
        // we are in MANDELBROT given the iteration made
        my_pixel_put(x, y, &fractal->img, BLACK);
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
 * 
 * z = z^2 + c => z 1 = c + c
 * 
 *      julia 
 *      ./fractal julia <real> <i>
 *      z = z^2 + c
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