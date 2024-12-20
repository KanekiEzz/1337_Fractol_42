/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:50 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/09 17:04:49 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	parse_fractal(int ac, char **av)
{
	if (ac <= 1)
		ft_putstr("Usage: ./fractol julia or ./fractol mandelbrot\n");
	else if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			ft_putstr("See image Mandelbrot\n");
		else if (ft_strcmp(av[1], "julia") == 0)
			ft_putstr("Usage: ./fractol julia <real> <imaginary>\n");
		else
			ft_putstr("Usage: ./fractol julia or ./fractol mandelbrot\n");
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
        if (ft_atof(av[2]) == 0.0 || ft_atof(av[3]) == 0.0)
			ft_putstr("Please add valid numbers, example: -0.7269 0.1889\n");
        else
			ft_putstr( "See image Julia\n");
    }
    else
		ft_putstr("Usage: ./fractol julia <real> <imaginary> or ./fractol mandelbrot\n");
}

// int	main(int ac, char **av)
// {
// 	t_fractal fractal;

// 	// parse_fractal(ac, av);

// 	fractal_init(&fractal);
// 	// fractal_render(&fractal);
// 	mlx_loop(fractal.mlx_connection);

// 	return (0);
// }


int	main(int ac, char **av)
{
	t_fractal	fractal;


		printf(":kaneki\n");
	if ((2 == ac && !ft_strcmp(av[1], "mandelbrot")) || (4 == ac && !ft_strcmp(av[1], "julia")))
	{
		fractal.name = av[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		//TL;DR
		//Prompt correct, kick off the application
		//1)
		fractal_init(&fractal); // windows display
		//2)
		fractal_render(&fractal);
		//3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		printf("l3almya :kaneki\n");
		ft_putstr(ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
}