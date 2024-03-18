/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:04 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/18 12:33:05 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_max_width(char **render)
{
    size_t  max;
    size_t  temp_max;
    size_t  x;

    max = 0;
    temp_max = 0;
    x = 0;
    while(render[0][x++])
    {
        temp_max =ft_strlen(render[0][x]);
        if (temp_max > max)
            max = temp_max;
    }
    return (max);
}

void    ft_check_square(char **render, char dot)
{
    char    tmp1;
    char    tmp2;
    size_t  y;

    if(!render)
        return ;
    y = ft_max_width(render);
}