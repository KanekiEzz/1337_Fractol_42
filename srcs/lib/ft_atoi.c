/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:54 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/06 12:09:12 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int ft_atoi(char *str)
{
    int sign;
    int resu;

    sign = 1;
    resu = 0;
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        resu = resu * 10 + (*str - '0');
        str++;
    }
    return sign * resu;
}

// int main()
// {
//     int i = ft_atoi("+1246");
//     if (i==0)
//     {
//         printf("should -number not --number or -+number");
//     }
//     else
//         printf("creat");
// }