/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:54:57 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/04 15:54:58 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_cube  cube;

	if (argc != 2)
		{
            printf("Invalid input\n");
            return (1);
        }
    ///////inizia variabili
    ft_check_map(&cube, argv[1]);//FIXARE CONTROLLO SU CARATTERI NON CONSENTITI 
    ft_init_window(&cube);
	
}

void    ft_check_map(t_cube *cube, char *path)
{
    if (ft_check_file(path, ".cub"))
        return ft_error("Invalid file format", cube);
    cube->map.f_map = 0;
	ft_parse(cube, path);
    if (cube->map.f_map == 1)
        ft_error("Error file format", cube);
    ft_check_elements(cube);
    ft_check_square(&cube->map.map, '.');
    ft_map_parse(cube);

    
}

int     ft_check_file(char *file, char *extencion)
{
    char    *cpy;

    cpy = ft_strrchr(file, '.');
    if (cpy != NULL && !ft_strcmp(cpy, extencion))
        return (0);
    return (1);
}

void    ft_check_elements(t_cube *cube)
{
    size_t  x;
    size_t  y;

    y = -1;
    if (!cube->map.complete)
        ft_error("Error: invalid map", cube);
    while(cube->map.map[++y])
    {
        x = -1;
        while(cube->map.map[++x])
        {
            if (!ft_strchr("01NSEW", cube->map.map[y][x]))
                ft_error("Invalid character", cube);
        }
    }
    cube->map.y = y;
}

void    ft_map_parse(t_cube *cube)
{
    size_t  y;
    size_t  x;

    cube->player.spawn = 0;
    y = -1;
    while (cube->map.map[++y])
    {
        x = -1;
        while (cube->map.map[y][++x])
        {
            if (ft_strchr("0NSEW" , cube->map.map[y][x]))
            {
                if(!ft_close_vertical(cube, y, x))
                    ft_error("Error: map is not closed", cube);
                if(!ft_close_horizontal(cube, y, x))//////////////
                    ft_error("Error: map is not closed", cube);
            }
            if (ft_strchr("NSEW", cube->map.map[y][x]))
            {
                cube->player.spawn += 1;
                //ft_spawn_player();
            }
        }
    }
}

bool     ft_close_vertical(t_cube *cube, size_t y, size_t x)
{
    bool     r;
    bool     l;
    size_t  count;

    r = 0;
    l = 0;
    count = x;
    while (cube->map.map[y][--count] && r == 0)
    {
        //if (ft_strchr(".", cube->map.map[i][k]))
			//error("MAP NOT CLOSED", cube);
		if (ft_strchr("1", cube->map.map[y][count]))
			r = 1;
    }
    count = x;
    while (cube->map.map[y][++count])
    {
        //if (ft_strchr(".", cube->map.map[i][k]))
			//error("MAP NOT CLOSED", cube);
		if (ft_strchr("1", cube->map.map[y][count]))
			l = 1;
    }
    return (r & l);
}

bool     ft_close_horizontal(t_cube *cube, size_t y, size_t x)
{
	bool	up;
	bool	down;
	size_t	count;

	up = 0;
	down = 0;
	count = y;
	while (up == 0 && cube->map.map[--count])
	{
		if (ft_strchr(".", cube->map.map[count][x]))
			ft_error("MAP NOT CLOSED", cube);
		if (ft_strchr("1", cube->map.map[count][x]))
			up = 1;
	}
	count = y;
	while (down == 0 && cube->map.map[++count])
	{
		if (ft_strchr(".", cube->map.map[count][x]))
			ft_error("MAP NOT CLOSED", cube);
		if (ft_strchr("1", cube->map.map[count][x]))
			down = 1;
	}
	return (up && down);
}