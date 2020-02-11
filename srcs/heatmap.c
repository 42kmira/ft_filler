/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:37:38 by kmira             #+#    #+#             */
/*   Updated: 2020/02/10 20:24:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_heatamp(int height, int width)
{
	int	row;
	int	**heatmap;

	row = 0;
	heatmap = malloc(sizeof(*heatmap) * (height + 1));
	while (row <= height)
	{
		heatmap[row] = malloc(sizeof(**heatmap) * (width + 1));
		ft_bzero(heatmap[row], sizeof(**heatmap) * (width + 1));
		row++;
	}
	heatmap[row] = NULL;
	return (heatmap);
}

void	fill_heat_map(int **heat_map, int height, int width, int current)
{
	int	row;
	int	col;
	int	toggle;

	row = -1;
	toggle = 0;
	while (++row < height)
	{
		col = -1;
		while (++col < width)
			if (heat_map[row][col] == current)
			{
				if (row - 1 >= 0 && heat_map[row - 1][col] == -1)
					heat_map[row - 1][col] = current - 1;
				if (row + 1 < height && heat_map[row + 1][col] == -1)
					heat_map[row + 1][col] = current - 1;
				if (col - 1 >= 0 && heat_map[row][col - 1] == -1)
					heat_map[row][col - 1] = current - 1;
				if (col + 1 < width && heat_map[row][col + 1] == -1)
					heat_map[row][col + 1] = current - 1;
				toggle = 1;
			}
	}
	if (toggle == 1)
		fill_heat_map(heat_map, height, width, current - 1);
}

void	update_heatmap(t_filler_context *context)
{
	int		row;
	int		col;
	int		max;
	char	enemy_char;

	if (context->board_width < context->board_height)
		max = context->board_height;
	else
		max = context->board_width;
	if (context->player_char == P1)
		enemy_char = P2;
	else
		enemy_char = P1;
	row = -1;
	while (++row < context->board_height)
	{
		col = -1;
		while (++col < context->board_width)
			if ((context->board)[row][col] == enemy_char)
				(context->heatmap)[row][col] = max;
			else
				(context->heatmap)[row][col] = -1;
	}
	fill_heat_map(context->heatmap, context->board_height, context->board_width, max);
}
