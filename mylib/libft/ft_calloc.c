/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:21:16 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/15 19:54:54 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		ptr = malloc(1);
	else
	{
		ptr = (void *)malloc(size * nmemb);
		if (!ptr || nmemb > 16711568 / size)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
	}
	return (ptr);
}
