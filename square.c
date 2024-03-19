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

int     ft_max_width(char **map)
{
    size_t  max;
    size_t  temp_max;
    size_t  x;

    max = 0;
    temp_max = 0;
    x = 0;
    while(map[0][x++])
    {
        temp_max =ft_strlen(map[0][x]);
        if (temp_max > max)
            max = temp_max;
    }
    return (max);
}

void    ft_check_square(char **map, char dot)
{
    char    tmp1;
    char    tmp2;
    size_t  y;
    size_t  a;
    size_t  b;

    if(!map)
        return ;
    y = ft_max_width(map);
    a = -1;
    while(map[0][++a])
    {
        b = 0;
        b = strlen(map[0][a]);
        if (b < y)
        {
            tmp1 = 
        }
    }
}