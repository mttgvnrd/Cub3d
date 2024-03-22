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

void    ft_scan_map(t_cube *cube, char *line)
{
    if (cube->map.x < ft_strlen(line))
        cube->map.x = ft_strlen(line);
    if (ft_new_str_arr(line, cube))
    {
        ft_free(line);
        ft_error("Error, can't allocate map line", cube);
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
        ft_save_colour(&cube->map.floor_rgb, cube->line + 2);
    else if (!ft_strncmp(cube->line, "C", 1))
        ft_save_colour(&cube->map.ceiling_rgb, cube->line + 2);
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
        cube->map.f_map = 1;
    else
        ft_strncpy(pos, tmp, ft_strlen(tmp));
}

//controllo se tutte le texture sono state assegnate
int     parse_complete(t_cube *cube)
{
    if (cube->map.no && cube->map.so &&
        cube->map.we && cube->map.ea &&
        cube->map.floor_rgb.complete && 
        cube->map.ceiling_rgb.complete)
        {
            cube->map.complete = 1;
            return(1);
        }
        return(0);
}

void     ft_parse(t_cube *cube, char *path)
{
    int     fd;
    int     check;
    int     flag;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_error("Error, can't open the file\n", cube);
    check = 1;
    flag = 0;
    while (check > 0)
    {
        check = ft_get_next_line(fd, &cube->line);
        ft_map(cube);
        if (parse_complete(cube))
            {
                if(ft_strchr(cube->line, '1') && flag)
                    ft_scan_map(cube, cube->line);
                flag = 1;
            }
            ft_free(cube->line);
    }
    close(fd);
}
