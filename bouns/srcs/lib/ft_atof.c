/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:51:38 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/23 16:51:40 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

int is_digit(const char *str)
{
	int check;

	check = 1;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != '.')
		{
			check = 0;
			break;
		}
		check = 1;
		str++;
	}
	if (check == 0)
		return (0);
	return (1);
}

double chech_point(const char *str)
{
	int point = 0;
	while (*str)
	{
		if (*str == '.')
			point++;
		str++;
	}
	if(point > 1)
		return 0.0;
	return 1;
}

double ft_atof(const char *str)
{
	double result;
	int sign;

	result = 0.0;
	sign = 1;
	if (!*str)
		return (3);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!(chech_point(str) == 1))
		return (3);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		if (*(str + 1) == '.')
			return (1);
		str++;
	}
	if (is_digit(str) == 0 || (*str == '.' && !(*(str + 1) >= '0' && *(str + 1) <= '9')))
		return (3);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		double fraction = 0.1;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str - '0') * fraction;
			fraction *= 0.1;
			str++;
		}
	}
	return (result * sign);
}

