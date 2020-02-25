/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:44:41 by kmira             #+#    #+#             */
/*   Updated: 2020/02/24 17:00:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		out_out_bounds(int row, int col, t_filler_context *context)
{
	int	result;
	int	max_row;
	int	max_col;

	result = 0;
	max_col = context->board_width;
	max_row = context->board_height;
	if (row < 0 || col < 0)
		result = 1;
	if (row >= max_row || col >= max_col)
		result = 1;
	return (result);
}

int		another_piece_there(int row, int col, char **board)
{
	int	result;

	result = 0;
	if (board[row][col] == 'O' || board[row][col] == 'X')
		result = 1;
	return (result);
}

int		valid_placement(int row, int col, t_filler_context *context)
{
	int		result;

	result = 1;
	if (out_out_bounds(row, col, context) == 1 ||
		another_piece_there(row, col, context->board) == 1)
		result = 0;
	return (result);
}

int		get_sum(t_piece *root, t_filler_context *context,
				t_piece *piece_place, t_piece *spot)
{
	int		row;
	int		col;
	int		result;
	t_piece	*iter;

	result = 0;
	iter = root;
	while (iter != NULL)
	{
		row = spot->row_rel + (iter->row_rel - piece_place->row_rel);
		col = spot->col_rel + (iter->col_rel - piece_place->col_rel);
		if (iter != piece_place && valid_placement(row, col, context) == 0)
			return (-2147483648);
		else
			result += (context->heatmap)[row][col];
		iter = iter->next;
	}
	return (result);
}
