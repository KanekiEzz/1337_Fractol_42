/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:01:35 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/08 14:41:44 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


/*
    if MALLOC goes bad (improbable)
*/

static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}


void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (NULL == fractal->mlx_connection)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,  mlx_ptr: WIDTH,   size_x: HEIGHT,  size_y: fractal->name); title :
    if (NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection); mlx_ptr:
        free(fractal->mlx_connection); ptr:
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, mlx_ptr: WIDTH, HEIGHT); width: height:

    if(NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window); mlx_ptr: wind_ptr:
        mlx_destroy_display(fractal->mlx_connection); mlx_ptr:
        free(fractal->mlx_connection); ptr:
        malloc_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.line_length,
                                                &fractal->img.endian);
    // event_init(fractal); //TODO
    // data_init(fractal); //TODO
} 