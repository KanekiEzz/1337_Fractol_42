/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:51:38 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/24 15:52:16 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

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

double	check_point(const char *str)
{
	int	point;

	point = 0;
	while (*str)
	{
		if (*str == '.')
			point++;
		str++;
	}
	if (point > 1)
		return (0.0);
	return (1);
}

double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			result += (**str - '0') * fraction;
			fraction *= 0.1;
			(*str)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	if (!*str || !check_point(str))
		return (3);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!is_digit(str)
		|| (*str == '.'
			&& !(*(str + 1) >= '0' && *(str + 1) <= '9')))
		return (3);
	result = parse_integer_part(&str);
	result += parse_fractional_part(&str);
	return (result * sign);
}
