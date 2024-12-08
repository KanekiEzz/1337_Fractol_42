/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:24 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/08 14:56:48 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void handel_pixel(int x, int y, t_fractal *fractal)
{
    
}



/*
 *      ------800------
 *      |             |
 *      |             |
 *      |             |
 *      |             |
 *      ------800------
 *
 */

void frcatal_rebder(t_fractal *fractal)
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
}