/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:51 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/09 19:06:45 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/*
*   ECS or i press the x in the window
*   close the window
*   free the memory
*   exit the program
*   int (*f)(void *param)
* no leaks
*/

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    // mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

/*
 * keypress protocol
 * int (*f)(int keycode, void *param)
 */
// #define XK_Escape                        0xff1b
int key_handler(int keycode, t_fractal *fractal)
{
    // printf("NUMBER CLICK =>  %d\n", keycode);
    if (keycode == ESC)
        close_handler(fractal);
	else if (keycode == ENTER)
		close_handler(fractal);
    if (keycode == RIGHT)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keycode == LEFT)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keycode == UP)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keycode == DOWN)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keycode == ADD_COLOR) // +
        fractal->max_iter += 10;
    else if (keycode == MINUS_COLOR) // -
        fractal->max_iter -= 10;

    // refresh the image;
    fractal_render(fractal);

    return 0;
}


/*
*   int (*f)(int button, int x, int y ,void *param)
*/
void convert_to_complex(int x, int y, t_complex *c, t_fractal *fractal)
{
    c->x = fractal->shift_x + (x - WIDTH / 2.0) * fractal->zoom / WIDTH;
    c->y = fractal->shift_y + (y - HEIGHT / 2.0) * fractal->zoom / HEIGHT;
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == ZOOM_IN || button == ZOOM_OUT)
    {
        t_complex z_mouse;
        double zoom_factor = (button == ZOOM_IN) ? 1.1 : 0.9;

        // Convert mouse coordinates to complex plane
        convert_to_complex(x, y, &z_mouse, fractal);

        // Adjust the view to zoom in/out centered on the mouse position
        fractal->zoom *= zoom_factor;
        fractal->shift_x = z_mouse.x - (z_mouse.x - fractal->shift_x) * zoom_factor;
        fractal->shift_y = z_mouse.y - (z_mouse.y - fractal->shift_y) * zoom_factor;

        // Redraw the fractal
        fractal_render(fractal);
        mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
    }
    return 0;
}


/*
 * TRACK the mouse
 * to change julia dynamically
 * int (*f)(int x, int y, void *param)
*/
// int	julia_track(int x, int y, t_fractal *fractal)
// {
// 	if (!ft_strcmp(fractal->name, "julia"))
// 	{
// 		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
// 		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
// 		fractal_render(fractal);
// 	}
// 	return 0;
// }