/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:50 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/06 22:14:00 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parse_fractal(int ac, char **av)
{
	if (ac <= 1)
		write(1, "Usage: ./fractol julia or ./fractol mandelbrot\n", 49);
	else if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			write(1, "See image Mandelbrot\n", 21);
		else if (ft_strcmp(av[1], "julia") == 0)
			write(1, "Usage: ./fractol julia <real> <imaginary>\n", 41);
		else
			write(1, "Usage: ./fractol julia or ./fractol mandelbrot\n", 49);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
        if (ft_atof(av[2]) == 0.0 || ft_atof(av[3]) == 0.0)
            write(1, "Please add valid numbers, example: -0.7269 0.1889\n", 49);
        else
            write(1, "See image Julia\n", 17);
    }
    else
        write(1, "Usage: ./fractol julia <real> <imaginary> or ./fractol mandelbrot\n", 70);
}

int	main(int ac, char **av)
{
	parse_fractal(ac, av);
	return (0);
}
