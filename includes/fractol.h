/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/07 15:21:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H 
#define FRACTOL_H

//+++++++++start forbidden++++++++
#include <string.h>
#include <stdio.h>
//+++++++++end forbidden++++++++

#include <unistd.h>
#include <stdlib.h>
# include <limits.h>

typedef struct	s_complex
{
	double real; // x
	double im; // y
}				t_complex;


// ./src/lib/..
int	ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *str);
size_t	ft_strlen(const char *s);


#endif