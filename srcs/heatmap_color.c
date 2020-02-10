/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:14:04 by kmira             #+#    #+#             */
/*   Updated: 2020/02/10 13:28:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "filler.h"

int		get_red(int num, int max)
{
	double	red;
	double	h;
	int		c;

	c = 3 * max;
	h = max * .85;
	red = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)red);
}

int		get_blue(int num, int max)
{
	double	blue;
	double	h;
	int		c;

	c = 3 * max;
	h = max * .15;
	blue = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)blue);
}

int		get_green(int num, int max)
{
	double	green;
	double	h;
	int		c;

	c = max;
	h = max * .5;
	green = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)green);
}

char	*color_code(uint8_t red, uint8_t green, uint8_t blue)
{
	char	*result;

	asprintf(&result, "\e[38;2;%d;%d;%dm", red, green, blue);
	return (result);
}
