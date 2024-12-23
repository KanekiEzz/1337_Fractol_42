/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:50 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/23 16:51:17 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void parse_fractal(int ac, char **av, t_fractal *fractal)
{
    if (ac <= 1)
    {
        ft_putstr("Usage: ./fractol julia or ./fractol mandelbrot\n");
        exit(EXIT_FAILURE);
    }
		if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		{
			fractal->name = "mandelbrot";
			return ;
		}
    else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
    {
        fractal->name = "julia";
				fractal->julia_x = ft_atof(av[2]);
            fractal->julia_y = ft_atof(av[3]);
        if (ft_atof(av[2]) == 3 || ft_atof(av[3]) == 3)
        {
            ft_putstr("Please add valid numbers, example: -0.7269 0.1889\n");
            exit(EXIT_FAILURE);
        }
				return ;
    }
    ft_putstr("Usage: ./fractol julia <real> <imaginary> or ./fractol mandelbrot\n");
    exit(EXIT_FAILURE);
}

void f(){system("leaks fractol");}

int main(int ac, char **av)
{
	atexit(f);
    t_fractal fractal;

    parse_fractal(ac, av, &fractal);

    fractal_init(&fractal);
    fractal_render(&fractal);
    mlx_loop(fractal.mlx_connection);

    return 0;
}
