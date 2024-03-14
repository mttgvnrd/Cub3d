/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:13:13 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/11 13:13:15 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	ft_free(void *pt)
{
	free(pt);
	pt = NULL;
}

void	ft_clear_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
			ft_free(arr[i++]);
	}
	ft_free(arr);
	arr = NULL;
}

static int	ft_str_count(t_cube *cube)
{
	int	i;

	i = 0;
	if (!cube->map.render)
		return (i);
	else
		while (cube->map.render[++i])
			;
	return (i);
}

int ft_new_str_arr(char *str, t_cube *cube)
{
	int		x;
	int		j;
	char	**new_arr;
	char	*n_str;

	x = -1;
	j = -1;
	n_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!n_str)
		return (1);
	ft_strcpy(n_str, str);
	x = ft_str_count(cube);
	new_arr = ft_calloc((x + 2), sizeof(char *));
	if (!new_arr)
		return (1);
	while (++j < x)
		new_arr[j] = ft_strdup(cube->map.render[j]);
	new_arr[x] = n_str;
	new_arr[x + 1] = NULL;
	if (cube->map.render)
		ft_clear_arr(cube->map.render);
	cube->map.render = new_arr;
	return (0);
}

