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
    ft_check_map(&cube, argv[1]);
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

    x = -1;
    if (!cube->map.complete)
        ft_error("Error: invalid map", cube);
    while(cube->map.render[++y])
    {
        x = -1;
        while(cube->map.render[++x])
        {
            if (!ft_strchr("01NSEW", cube->map.render[y][x]))
                ft_error("Invalid character", cube);
        }
    }
    cube->map.y = y;
}