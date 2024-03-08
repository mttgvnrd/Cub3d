/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:28:10 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/08 12:28:11 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int     ft_parse(t_cube *cube, char *path)
{
    int     fd;
    int     check;
    int     flag;

    fd = open(path, O_RDONLY);
    check = 1;
    flag = 0;
    while (check > 1)
    {
        check = ft_get_next_line(fd, &cube->line);
        ft_map(cube);
    }
}


//analizzo il file della mappa e mi salvo i percorsi delle varie
//texture da assegnare e i colori 
void    ft_map(t_cube *cube)
{
    if (!ft_strncmp(cube->line, "NO", 2))
    {
        cube->map.no = ft_calloc(ft_strlen(cube->line + 3), sizeof(char *));
        save_pos(cube, cube->map.no);
    }
    else if (!ft_strncmp(cube->line, "SO", 2))
    {
        cube->map.so = ft_calloc(ft_strlen(cube->line + 3), sizeof(char *));
        save_pos(cube, cube->map.so);
    }
    else if (!ft_strncmp(cube->line, "EA", 2))
    {
        cube->map.ea = ft_calloc(ft_strlen(cube->line + 3), sizeof(char *));
        save_pos(cube, cube->map.ea);
    }
    else if (!ft_strncmp(cube->line, "WE", 2))
    {
        cube->map.we = ft_calloc(ft_strlen(cube->line + 3), sizeof(char *));
        save_pos(cube, cube->map.we);
    }
    else if (!ft_strncmp(cube->line, "F", 1))
        ft_save_colour(&cube->rgb, cube->line + 2);
    else if (!ft_strncmp(cube->line, "C", 1))
        ft_save_colour(&cube->rgb, cube->line + 2);
}

void    save_pos(t_cube *cube, char *pos)
{
    int     fd;
    char    *tmp;

    if (!pos)
        ft_error("Mem error", cube);
    if (cube->line + 3)
        tmp = cube->line + 3;
    fd = open(tmp, O_RDONLY);
    close(fd);
    if (fd == -1)
        cube->map.f_map == 1;
    else
        ft_strncpy(pos, tmp, ft_strlen(tmp));
}

void    ft_save_colour(t_rgb *rgb, char *code)
{
    
}