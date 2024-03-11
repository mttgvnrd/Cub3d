/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:27:10 by mgiovana          #+#    #+#             */
/*   Updated: 2024/03/08 15:27:11 by mgiovana         ###   ########.fr       */
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

int	ft_encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}


//salvo i valori rgb 
void	ft_save_colour(t_rgb *rgb, char *rgb_code)
{
	char	**rgb_split;

	rgb_split = ft_split(rgb_code, ',');
	if (rgb_split[0] && rgb_split[1] && rgb_split[2])
	{
		rgb->r = ft_atoi(rgb_split[0]);
		rgb->g = ft_atoi(rgb_split[1]);
		rgb->b = ft_atoi(rgb_split[2]);
	}
	if ((rgb->r < 0 || rgb->r > 255)
		|| (rgb->g < 0 || rgb->g > 255)
		|| (rgb->b < 0 || rgb->b > 255))
	{
		printf("Invalid RGB values, default settings entered\n");
		rgb->r = 42;
		rgb->g = 42;
		rgb->b = 42;
	}
	ft_clear_arr(rgb_split);
	rgb_split = NULL;
	rgb->full_rgb = ft_encode_rgb(rgb->r, rgb->g, rgb->b);
	rgb->complete = 1;
}


