/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:32:42 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/06 21:45:17 by iezzam           ###   ########.fr       */
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
	double re;
	double im;
}				t_complex;


// ./src/lib/..
int	ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *str);
size_t	ft_strlen(const char *s);


#endif