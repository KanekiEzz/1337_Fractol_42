/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:47:24 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/10 04:29:49 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void my_pixel_put(int x, int y, t_imag *img, int color)
{
    int offset = (y * img->line_length) + x * (img->bpp / 8);
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

void handel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (ft_strcmp(fractal->name, "julia") == 0)
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
        *c = *z;
}

static int interpolate_color(int color1, int color2, double t)
{
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    int r = r1 + t * (r2 - r1);
    int g = g1 + t * (g2 - g1);
    int b = b1 + t * (b2 - b1);

    return (r << 16) | (g << 8) | b;
}

static int get_smooth_color(int i, double z_mag, t_fractal *fractal)
{
    double smooth_value = i + 1 - log2(log2(z_mag) / log2(fractal->escape_value));
    double t = fmin(1.0, smooth_value / fractal->max_iter);

    int color_palette[] = { 0x262525, 0x4B0082, 0x8A2BE2, 0xc690f5, 0x9400D3, 0xFF00FF, 0x8B008B, 0xeff224, 0xd41717};

    int palette_size = sizeof(color_palette) / sizeof(color_palette[0]);
    int color_index1 = (int)(t * (palette_size - 1));
    int color_index2 = (color_index1 + 1) % palette_size;
    double local_t = (t * (palette_size - 1)) - color_index1;

    return interpolate_color(color_palette[color_index1], color_palette[color_index2], local_t);
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z = {
        .x = ((double)x / WIDTH - 0.5) * 4.0 * fractal->zoom ,
        .y = ((double)y / HEIGHT - 0.5) * 4.0 * fractal->zoom
    };
    t_complex c;
    handel_vs_julia(&z, &c, fractal);

    int i = 0;
    double z_mag;
    while (i < fractal->max_iter)
    {
        z = sum_complex(square_complex(z), c);
        z_mag = z.x * z.x + z.y * z.y;

        if (z_mag > fractal->escape_value)
        {
            int color = get_smooth_color(i, z_mag, fractal);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
    }

    my_pixel_put(x, y, &fractal->img, 0x000000);
}

void fractal_render(t_fractal *fractal)
{
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            handle_pixel(x, y, fractal);
            ++x;
        }
        ++y;
    }

    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window,
                            fractal->img.img_ptr, 0, 0);
}