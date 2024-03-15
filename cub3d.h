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
    char    **render;
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
    char    *line;

    void    *mlx;
    void    *window;

    int     lines;
    int     fd;

    bool    f_wind;

    t_map   map;
    t_rgb   rgb;

}   t_cube;

//MAIN
void    ft_init_window(t_cube *cube);
void    ft_check_map(t_cube *cube, char *path);
int     ft_check_file(char *file, char *extencion);
void    ft_check_elements(t_cube *cube);

//RGB
int	    ft_encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	ft_save_colour(t_rgb *rgb, char *rgb_code);

//UTILS
void	ft_free(void *pt);
void	ft_clear_arr(char **arr);
static int	ft_str_count(t_cube *cube);
int     ft_new_str_arr(char *str, t_cube *cube);

//PARSE
int     ft_parse(t_cube *cube, char *path);
int     parse_complete(t_cube *cube);
void    save_pos(t_cube *cube, char *pos);
void    ft_map(t_cube *cube);
void    ft_scan_map(t_cube *cube, char *line);

//EXIT
void    ft_error(char *str, t_cube *cube);
int     ft_quit(t_cube *cube);

//INIT
void ft_init_window(t_cube *cube);


#endif
