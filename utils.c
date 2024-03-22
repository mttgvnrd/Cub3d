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
	if (!cube->map.map)
		return (i);
	else
		while (cube->map.map[++i])
			;
	return (i);
}

//aggiunge una nuova stringa all'array della mappa
int ft_new_str_arr(char *str, t_cube *cube)
{
	char	**new_map;
	char	*new_str;
	int		x;
	int		j;

	x = -1;
	j = -1;
	new_str = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!new_str)
		return (1);
	ft_strcpy(new_str, str);
	x = ft_str_count(cube);
	new_map = ft_calloc((x + 2), sizeof(char *));
	if (!new_map)
		return (1);
	while (++j < x)
		new_map[j] = ft_strdup(cube->map.map[j]);
	new_map[x] = new_str;
	new_map[x + 1] = NULL;
	if (cube->map.map)
		ft_clear_arr(cube->map.map);
	cube->map.map = new_map;
	return (0);
}
