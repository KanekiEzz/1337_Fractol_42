/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:51 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/09 06:39:36 by iezzam           ###   ########.fr       */
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
    printf("%d\n", keycode);
    if (keycode == 53)
        close_handler(fractal);
    if (keycode == 124)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keycode == 123)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keycode == 126)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keycode == 125)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keycode == 24) // 0
        fractal->max_iter += 10;
    else if (keycode == 27) // -
        fractal->max_iter -= 10;

    // refresh the image;
    fractal_render(fractal);

    return 0;
}

/*
*   int (*f)(int button, int x, int y ,void *param)
*/

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    // zoom in
    if (button == 5) // Scroll up (zoom in)
    {
        fractal->zoom *= 0.95; // Increase the zoom level
    }
    // zoom out
    else if (button == 4) // Scroll down (zoom out)
    {
        fractal->zoom *= 1.05; // Decrease the zoom level
    }

    fractal_render(fractal); // Redraw the fractal with updated parameters
    return 0;
}

/*
 * TRACK the mouse
 * to change julia dynamically
 * int (*f)(int x, int y, void *param)
*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return 0;
}