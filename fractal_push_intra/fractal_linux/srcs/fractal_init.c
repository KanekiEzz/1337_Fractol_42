/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:01:35 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/09 04:47:53 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/*
    if MALLOC goes bad (improbable)
*/

static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal->escape_value = 4; // 2 ^ 2, my hypotenuse
    fractal->max_iter = 42;    // see point(img) mandelbrot in julia

    //shift keyboard
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;

    // zoom mouse
    fractal->zoom = 1.0;
}

void event_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window,
            KeyPress,
            KeyPressMask,
            key_handler, // todo
            fractal);

    mlx_hook(fractal->mlx_window,
            ButtonPress,
            ButtonPressMask,
            mouse_handler, // todo
            fractal);

    mlx_hook(fractal->mlx_window,
        DestroyNotify,
        StructureNotifyMask,
        close_handler, // todo
        fractal);

    mlx_hook(fractal->mlx_window,
    MotionNotify,
    PointerMotionMask,
    julia_track, // todo
    fractal);
}

// INIT FUNCTION
// INTIALIAZES THE VARIABLES OF FRACTAL STRUCT

void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (NULL == fractal->mlx_connection)
    {
        malloc_error();
    }
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.line_length,
                                                &fractal->img.endian);
    event_init(fractal);
    data_init(fractal);
}