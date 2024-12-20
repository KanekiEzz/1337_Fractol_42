/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:50 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/10 04:52:29 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void parse_fractal(int ac, char **av)
{
	t_fractal fractal = {0};
	int use = 0;
	if (ac <= 1){
		ft_putstr("Usage: ./fractol julia or ./fractol mandelbrot\n");
		exit(EXIT_FAILURE);}
	if ((2 == ac && !ft_strcmp(av[1], "mandelbrot")) || (4 == ac && !ft_strcmp(av[1], "julia")))
	{
		fractal.name = av[1];
		if (ac == 2)
		{
			if (ft_strcmp(av[1], "mandelbrot") == 0)
				use = 1;
			else if (ft_strcmp(av[1], "julia") == 0)
			{
				ft_putstr("Usage: ./fractol julia <real> <imaginary>\n");
				exit(EXIT_FAILURE);
			}
			else{
				ft_putstr("Usage: ./fractol julia or ./fractol mandelbrot\n");
				exit(EXIT_FAILURE);
				}
		}
		else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
		{
			fractal.julia_x = ft_atof(av[2]);
			fractal.julia_y = ft_atof(av[3]);
			if (ft_atof(av[2]) == 0.0 || ft_atof(av[3]) == 0.0){
				ft_putstr("Please add valid numbers, example: -0.7269 0.1889\n");
				exit(EXIT_FAILURE);
				}
			else
				use = 1;
		}
		if (use == 1)
		{
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_connection);
		}
		else
		{
			ft_putstr("Usage: ./fractol julia <real> <imaginary> or ./fractol mandelbrot\n");
			exit(EXIT_FAILURE);
		}
	}
	// else
	// {
	// 	ft_putstr(ERROR_MESSAGE);
	// 	exit(EXIT_FAILURE);
	// }
}

int main(int ac, char **av)
{
	parse_fractal(ac, av);
	// return (0);
}

// int main(int ac, char **av)
// {
// 	t_fractal fractal;

// 	printf(":kaneki\n");
// 	if ((2 == ac && !ft_strcmp(av[1], "mandelbrot")) || (4 == ac && !ft_strcmp(av[1], "julia")))
// 	{
// 		fractal.name = av[1];
// 		if (!ft_strcmp(fractal.name, "julia"))
// 		{
// 			fractal.julia_x = atodbl(av[2]);
// 			fractal.julia_y = atodbl(av[3]);
// 		}
// 		fractal_init(&fractal); // windows display
// 		// 2)
// 		fractal_render(&fractal);
// 		// 3)
// 		mlx_loop(fractal.mlx_connection);
// 	}
// 	else
// 	{
// 		printf("l3almya :kaneki\n");
// 		ft_putstr(ERROR_MESSAGE);
// 		exit(EXIT_FAILURE);
// 	}
// }