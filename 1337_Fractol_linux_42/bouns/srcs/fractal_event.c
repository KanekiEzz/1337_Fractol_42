/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:18:51 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/30 10:10:51 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
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
	else if (keycode == 24)
		fractal->max_iter += 10;
	else if (keycode == 27)
		fractal->max_iter -= 10;
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	old_zoom;

	old_zoom = fractal->zoom;
	if (button == 5)
		fractal->zoom *= 0.95;
	else if (button == 4)
		fractal->zoom *= 1.05;
	else if (button == 3)
		mlx_hook(fractal->mlx_window, 6, 1L << 6, julia_track, fractal);
	else if (button == 2)
		mlx_hook(fractal->mlx_window, 6, 1L << 6, 0, fractal);
	fractal->shift_x += map(x, -2, +2, WIDTH) * (old_zoom - fractal->zoom);
	fractal->shift_y += map(y, +2, -2, HEIGHT) * (old_zoom - fractal->zoom);
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
