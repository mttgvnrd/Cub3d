/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:15:59 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/05 12:16:00 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void ft_error(char *str, t_cube *cube)
{
    (void)cube;
    printf("Error %s\n", str);
    ft_quit(cube);
}

int ft_quit(t_cube *cube)
{
    if (cube->f_wind)
    {
        mlx_clear_window(cube->mlx, cube->window);
        mlx_destroy_window(cube->mlx, cube->window);
    }
    return (1);
}