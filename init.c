/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:55:06 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/04 15:55:08 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init_window(t_cube *cube)
{
    cube->mlx = mlx_init();
    if (!cube->mlx)
        ft_error("Can't create the window", cube);
    cube->window = mlx_new_window(cube->mlx, WIN_X, WIN_Y, "Cub3d");
    if (!cube->window)
        ft_error("Can't create the window", cube);
    cube->f_wind = 1;
}