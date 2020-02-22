/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:14:04 by kmira             #+#    #+#             */
/*   Updated: 2020/02/22 15:41:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "filler.h"

int		get_r(int num, int max)
{
	double	red;
	double	h;
	int		c;

	c = max;
	h = max * .88;
	red = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)red);
}

int		get_b(int num, int max)
{
	double	blue;
	double	h;
	int		c;

	c = max * .6;
	h = max * .7;
	blue = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)blue);
}

int		get_g(int num, int max)
{
	double	green;
	double	h;
	int		c;

	c = max * .7;
	h = max * .8;
	green = 250 * powf(M_E, -1 * powf(num - h, 2) / (c));
	return ((int)green);
}

char	*colour_code(uint8_t red, uint8_t green, uint8_t blue, char *dest)
{
	snprintf(dest, 50, "\e[38;2;%d;%d;%dm", red, green, blue);
	return (dest);
}
