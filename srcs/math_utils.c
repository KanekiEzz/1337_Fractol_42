/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:10:16 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/08 15:14:29 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


/*

    [0..799] -> [-2..2]
*/

// old_max != old_min
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return new_min + (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min);
}