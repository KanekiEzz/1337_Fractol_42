/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:51 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/10 04:23:29 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int keycode, t_fractal *fractal)
{
    if (keycode == ESC)
        close_handler(fractal);
    fractal_render(fractal);

    return 0;
}

int mouse_handler(int button, t_fractal *fractal)
{
    if (button == 5)
        fractal->zoom *= 0.95;
    else if (button == 4)
        fractal->zoom *= 1.05;

    fractal_render(fractal);
    return 0;
}
