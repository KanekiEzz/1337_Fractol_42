/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:03:33 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/24 14:09:11 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

void ft_putstr_colored(const char *str, const char *color)
{
    write(1, color, ft_strlen(color));
    write(1, str, ft_strlen(str));
    write(1, "\033[0m", 4);
}

void print_kaneki(void)
{
    const char *kaneki_art = 
        "        ##    ##    ###    ##    ## ######## ##    ## ####\n"
        "        ##   ##    ## ##   ###   ## ##       ##   ##   ## \n"
        "        ##  ##    ##   ##  ####  ## ##       ##  ##    ## \n"
        "        #####    ##     ## ## ## ## ######   #####     ## \n"
        "        ##  ##   ######### ##  #### ##       ##  ##    ## \n"
        "        ##   ##  ##     ## ##   ### ##       ##   ##   ## \n"
        "        ##    ## ##     ## ##    ## ######## ##    ## ####\n";
    
    printf("\033[1;34m%s\033[0m", kaneki_art);
}


void print_usag(void)
{
    const char *header_color = "\033[1;36m";
    const char *option_color = "\033[1;33m";
    const char *reset_color = "\033[0m";

	print_kaneki();	

    ft_putstr_colored("Usage:\n", header_color);
    ft_putstr_colored(" 1:\t", option_color);
    ft_putstr_colored("./fractol julia <real> <imaginary>\n", reset_color);
    ft_putstr_colored("  or\n", header_color);
    ft_putstr_colored(" 2:\t", option_color);
    ft_putstr_colored("./fractol mandelbrot\n", reset_color);
    ft_putstr_colored("  or\n", header_color);
    ft_putstr_colored(" 3:\t", option_color);
    ft_putstr_colored("./fractol burningship\n", reset_color);
    ft_putstr_colored("  or\n", header_color);
    ft_putstr_colored(" 4:\t", option_color);
    ft_putstr_colored("./fractol tricorn\n", reset_color);
    ft_putstr_colored("  or\n", header_color);
    ft_putstr_colored(" 5:\t", option_color);
    ft_putstr_colored("./fractol celtic\n", reset_color);
}
