/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:37:38 by kmira             #+#    #+#             */
/*   Updated: 2020/02/22 15:38:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_heatamp(int height, int width)
{
	int	row;
	int	**heatmap;

	row = 0;
	heatmap = malloc(sizeof(*heatmap) * (height + 1));
	while (row < height)
	{
		heatmap[row] = malloc(sizeof(**heatmap) * (width + 1));
		ft_bzero(heatmap[row], sizeof(**heatmap) * (width + 1));
		row++;
	}
	heatmap[row] = NULL;
	return (heatmap);
}

#define UNFILLED -1

void	update_spot(int row, int col, int current, t_filler_context *context)
{
	char	**board;
	int		**heatmap;

	board = context->board;
	heatmap = context->heatmap;
	if (out_out_bounds(row, col, context) == 0
		&& heatmap[row][col] == UNFILLED
		&& ft_tolower(board[row][col]) != context->player_char)
	{
		heatmap[row][col] = current - 1;
	}
}

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

void	fill_heat_map(int **heat_map, int current, t_filler_context *context)
{
	int		row;
	int		col;
	int		toggle;
	char	**board;

	row = -1;
	toggle = 0;
	board = context->board;
	while (++row < context->board_height)
	{
		col = -1;
		while (++col < context->board_width)
			if (heat_map[row][col] == current)
			{
				update_spot(row + UP, col, current, context);
				update_spot(row + DOWN, col, current, context);
				update_spot(row, col + RIGHT, current, context);
				update_spot(row, col + LEFT, current, context);
				toggle = 1;
			}
	}
	if (toggle == 1)
		fill_heat_map(heat_map, current - 1, context);
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
			if (ft_tolower((context->board)[row][col]) == enemy_char)
				(context->heatmap)[row][col] = max;
			else
				(context->heatmap)[row][col] = UNFILLED;
	}
	fill_heat_map(context->heatmap, max, context);
}
