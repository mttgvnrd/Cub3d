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
    ft_check_fd(cube, path);

    
}

int     ft_check_file(char *file, char *extencion)
{
    char    *cpy;

    cpy = ft_strrchr(file, '.');
    if (cpy != NULL && !ft_strcmp(cpy, extencion))
        return (0);
    return (1);
}

void    ft_check_fd(t_cube *cube, char *path)
{
    int     i;
    int     stop;

	cube->lines = 0;
    cube->fd = open(path, O_RDONLY);
    if (cube->fd == -1)
        ft_error("Can't open the file", cube);
	cube->line = get_next_line(cube->fd);
	while (cube->line != NULL)
	{
		free(cube->line);
		cube->line = get_next_line(cube->fd);
		cube->lines++;
	}
	free(cube->line);
	close(cube->fd);
	get_matrix(path, cube);
	return (0);
}

void	get_matrix(char *path, t_cube *cube)
{
	static char	*buff;

	cube->fd = open(path, O_RDONLY);
	cube->line = get_next_line(cube->fd);
	if (!buff)
		buff = ft_calloc2(sizeof(char), 1);
	while (cube->line != NULL)
	{
		buff = ft_strjoin2(buff, cube->line);
		free(cube->line);
		cube->line = get_next_line(cube->fd);
	}
	close(cube->fd);
	free(cube->line);
	p->matrix.mat = ft_split(buff, '\n');
	free(buff);
}