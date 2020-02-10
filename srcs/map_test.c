/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 09:01:04 by kmira             #+#    #+#             */
/*   Updated: 2020/02/10 13:11:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**init_map(void)
{
	char	**result;

	result = malloc(sizeof(*result) * (40));
	result[0] = "...............................";
	result[1] = "...............................";
	result[2] = "..OOO..........................";
	result[3] = "....O..........................";
	result[4] = "....O..........................";
	result[5] = "....OOOO...................O...";
	result[6] = "...............................";
	result[7] = "...............................";
	result[8] = "...............................";
	result[9] = "...............................";
	result[10] = "...............................";
	result[11] = "...............................";
	result[12] = "..............X................";
	result[13] = "...............................";
	result[14] = "...............................";
	result[15] = "...............................";
	result[16] = "...............................";
	result[17] = "...............................";
	result[18] = ".......................O.......";
	result[19] = "...............................";
	result[20] = "...............................";
	result[21] = "...............................";
	result[22] = "...............................";
	result[23] = "...............................";
	result[24] = "...............................";
	result[25] = "...............................";
	result[26] = "...............................";
	result[27] = "..................OOO..........";
	result[28] = "...............................";
	result[29] = "...............................";
	result[30] = "...............................";
	result[31] = "O..............................";
	result[32] = NULL;
	return (result);
}

char	*color_code(uint8_t red, uint8_t green, uint8_t blue)
{
	char	*result;

	asprintf(&result, "\e[38;2;%d;%d;%dm", red, green, blue);
	return (result);
}

#include <math.h>

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

# define ANSI_RESET "\033[0m"

void	print_heat_map(int **heat_map, int height, int width, int max)
{
	int		row;
	int		col;
	int		num;
	char	*color;

	row = 0;
	max = max / 2;
	while (row <= height)
	{
		col = 0;
		while (col < width)
		{
			num = heat_map[row][col] - max;
			color = color_code(get_red(num, max), get_green(num, max), get_blue(num, max));
			printf("%s%4d ", color, heat_map[row][col]);
			col++;
		}
		printf(ANSI_RESET"\n");
		printf(ANSI_RESET"\n");
		row++;
	}
}

void	fill_heat_map(int **heat_map, int height, int width, int current)
{
	int	row;
	int	col;
	int	toggle;

	row = 0;
	toggle = 0;
	while (row <= height)
	{
		col = 0;
		while (col < width)
		{
			if (heat_map[row][col] == current)
			{
				if (row - 1 >= 0 && heat_map[row - 1][col] == -1)
					heat_map[row - 1][col] = current - 1;
				if (row + 1 <= height && heat_map[row + 1][col] == -1)
					heat_map[row + 1][col] = current - 1;
				if (col - 1 >= 0 && heat_map[row][col - 1] == -1)
					heat_map[row][col - 1] = current - 1;
				if (col + 1 < width && heat_map[row][col + 1] == -1)
					heat_map[row][col + 1] = current - 1;
				toggle = 1;
			}
			col++;
		}
		row++;
	}
	if (toggle == 1)
		fill_heat_map(heat_map, height, width, current - 1);
}

int	main(int aa, char **args)
{
	char	**map;
	int		width;
	int		height;

	map = init_map();
	while (map[height] != NULL)
		height++;
	while (map[0][width] != '\0')
		width++;
	height--;

	int		row;
	int		col;
	int		**heat_map;
	int		max;

	row = 0;
	if (width > height)
		max = width;
	else
		max = height;

	heat_map = malloc(sizeof(*heat_map) * (height + 1));
	while (row <= height)
	{
		col = 0;
		heat_map[row] = malloc(sizeof(**heat_map) * (width + 1));
		while (col < width)
		{
			if (map[row][col] == 'O')
				heat_map[row][col] = max;
			else
				heat_map[row][col] = -1;
			col++;
		}
		row++;
	}
	fill_heat_map(heat_map, height, width, max);
	print_heat_map(heat_map, height, width, max);
	return (0);
}
