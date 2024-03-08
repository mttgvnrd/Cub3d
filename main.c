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
    /////
	ft_parse(cube, path);

    
}

int     ft_check_file(char *file, char *extencion)
{
    char    *cpy;

    cpy = ft_strrchr(file, '.');
    if (cpy != NULL && !ft_strcmp(cpy, extencion))
        return (0);
    return (1);
}

