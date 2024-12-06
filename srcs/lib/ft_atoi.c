/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:54 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/06 22:06:45 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	_check_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	is_digit(const char *str)
{
	int	check;

	check = 1;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != '.')
		{
			check = 0;
			break ;
		}
		check = 1;
		str++;
	}
	if (check == 0)
		return (0);
	return (1);
}

double	ft_atof(const char *str)
{
	double	result;
	double	frac_part;
	int		sign;
	int		decimal_found;

	result = 0.0;
	frac_part = 0.0;
	sign = 1;
	decimal_found = 0;
	if (!*str)
		return (0.0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (is_digit(str) == 0 || (*str == '.' && !(*(str + 1) >= '0' && *(str + 1) <= '9')))
		return (0.0);
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (_check_overflow(sign));
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		double fraction = 0.1;
		while(*str >= '0' && *str <= '9')
		{
			result += (*str - '0') * fraction;
			fraction *= 0.1;
			str++;
		}
	}
	return (result * sign);
}
