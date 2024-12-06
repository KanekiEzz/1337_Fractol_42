/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:50 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/06 12:12:39 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void parse_fractal()
{
}

int main(int ac, char **av)
{
	// t_complex	acav;
	(void)ac;
	(void)av;

	if (ac <= 1)
		write(1, "add this ./fractol julia or ./fractol mandelbrot\n", 49);
	else if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
		{
			write(1, "see image mandelbrot\n", 21);
		}
		else
			return write(1, "add this ./fractol julia <number> <number> or ./fractol mandelbrot\n", 49);
	}
	else if (ac == 4)
	{
		if (ft_strcmp(av[2] , "julia") == 0)
		{
			write(1, "see image julia\n", 17);
			if ((av[3]) == 0)
				write(1, "should -number not --number or -+number\n", 41);
		}
	}
	else
		exit(0);
	// parse_fractal(&acav, av[1]);
	return 0;
}