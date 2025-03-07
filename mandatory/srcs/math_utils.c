/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:10:16 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/24 15:39:54 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

double	map(double point, double new_min, double new_max, double old_max)
{
	return (new_min + ((new_max - new_min) * (point / old_max)));
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_complex	square_complex(t_complex a)
{
	t_complex	result;

	result.x = (a.x * a.x) - (a.y * a.y);
	result.y = 2 * a.x * a.y;
	return (result);
}
