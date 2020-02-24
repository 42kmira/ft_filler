/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:14:04 by kmira             #+#    #+#             */
/*   Updated: 2020/02/24 15:32:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "filler.h"

int		get_r(int num, int max)
{
	int	red;
	int	h1;
	int	h2;

	h1 = (29 * max) / 32;
	h2 = (35 * max) / 32;
	red = -(250 * 4) * ((num - h1) * (num - h2)) / ((h1 - h2) * (h1 - h2));
	if (red < 0)
		red = 0;
	return (red);
}

int		get_b(int num, int max)
{
	int	blue;
	int	h1;
	int	h2;

	h1 = (27 * max) / 32;
	h2 = (31 * max) / 32;
	blue = -(250 * 4) * ((num - h1) * (num - h2)) / ((h1 - h2) * (h1 - h2));
	if (blue < 0)
		blue = 0;
	return (blue);
}

int		get_g(int num, int max)
{
	int	green;
	int	h1;
	int	h2;

	h1 = (28 * max) / 32;
	h2 = (32 * max) / 32;
	green = -(200 * 4) * ((num - h1) * (num - h2)) / ((h1 - h2) * (h1 - h2));
	if (green < 0)
		green = 0;
	return (green);
}

char	*colour_code(uint8_t red, uint8_t green, uint8_t blue, char *dest)
{
	char	*red_str;
	char	*green_str;
	char	*blue_str;

	red_str = ft_itoa(red);
	green_str = ft_itoa(green);
	blue_str = ft_itoa(blue);

	ft_bzero(dest, COL_BUFF);
	ft_strcat(dest, "\e[38;2;");
	ft_strcat(dest, red_str);
	ft_strcat(dest, ";");
	ft_strcat(dest, green_str);
	ft_strcat(dest, ";");
	ft_strcat(dest, blue_str);
	ft_strcat(dest, "m");
	free(red_str);
	free(green_str);
	free(blue_str);
	return (dest);
}
