/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaneki <kaneki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:01:35 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/21 02:23:14 by kaneki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal->escape_value = 4;
    fractal->max_iter = 24;

    //shift keyboard
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;

    // zoom mouse
    fractal->zoom = 1.0;
}

void event_init(t_fractal *fractal)
{
    // Keyboard events
    mlx_hook(fractal->mlx_window, 2, 1L, key_handler, fractal);

    // Mouse click events
    mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_handler, fractal);

    mlx_hook(fractal->mlx_window,  17, 1L << 17, close_handler, fractal);

    mlx_hook(fractal->mlx_window, 6, 1L << 6, julia_track, fractal);
}

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
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
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