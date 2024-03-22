/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:04 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/18 12:33:05 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ritorna la larghezza massima dell'array di stringhe
int     ft_max_width(char ***map)
{
    size_t  max;
    size_t  temp_max;
    size_t  x;

    max = 0;
    temp_max = 0;
    x = 0;
    while(map[0][x++])
    {
        temp_max = ft_strlen(map[0][x]);
        if (temp_max > max)
            max = temp_max;
    }
    return (max);
}

//funzione che serve ad aggiungere spazi vuoti fino a raggiungere la larghezza massima della mappa
void    ft_check_square(char ***map, char dot)
{
    char    *tmp1;
    char    *tmp2;
    size_t  x;
    size_t  a;
    size_t  b;

    if(!map)
        return ;
    x = ft_max_width(map);
    a = -1;
    while(map[0][++a])
    {
        b = 0;
        b = strlen(map[0][a]);
        if (b < x)
        {
            tmp2 = ft_fill_space(dot, x - b);
            tmp1 = ft_strjoin(map[0][a], tmp2);
            ft_free(map[0][a]);
            map[0][a] = tmp1;
            ft_free(tmp2);
        }
    }
}

char    *ft_fill_space(char c,size_t size)
{
	size_t	i;
	char	*str;
	char	*tmp;
	char	*c_str;

	i = -1;
	str = ft_calloc(sizeof(char *), 1);
	c_str = ft_calloc(sizeof(char *), 1);
	c_str[0] = c;
	c_str[1] = '\0';
	while (++i < size)
	{
		tmp = ft_strjoin(str, c_str);
		ft_free(str);
		str = tmp;
	}
	ft_free(c_str);
	return (str);
}
