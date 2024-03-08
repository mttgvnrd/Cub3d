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

void	ft_save_rgb(t_rgb *rgb, char *rgb_code)
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
		write(1, "RGB VALUES ARE INCORRECT, RESETING VALUES\n", 43);
		rgb->r = 42;
		rgb->g = 42;
		rgb->b = 42;
	}
	ft_clean_arr(rgb_split);
	rgb_split = NULL;
	rgb->full_rgb = ft_encode_rgb(rgb->r, rgb->g, rgb->b);
	rgb->fill = TRUE;
}