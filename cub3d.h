/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:57:32 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/04 15:57:35 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

# include "./minilibx-linux/mlx.h"
# include "./src/libft/libft.h"
# include "./src/GNL/get_next_line.h"

#define WIN_X 1300
#define WIN_Y 770

typedef struct rgb
{
    bool    complete;
    int     r;
    int     g;
    int     b;
    int     full_rgb;
}   t_rgb;

typedef struct map
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    t_rgb   floor_rgb;
    t_rgb   ceiling_rgb;
    size_t  y;
    size_t  x;

    bool    f_map;
    bool    complete;

}   t_map;


typedef struct cube
{
    void    *mlx;
    void    *window;

    char    *line;

    int     lines;
    int     fd;

    bool    f_wind;

    t_map   map;
    t_rgb   rgb;

}   t_cube;

void ft_init_window(t_cube *cube);
void ft_error(char *str, t_cube *cube);

#endif
