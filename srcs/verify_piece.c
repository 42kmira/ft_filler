/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:44:41 by kmira             #+#    #+#             */
/*   Updated: 2020/02/16 19:07:39 by kmira            ###   ########.fr       */
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

int		is_valid_placement(int row, int col, t_filler_context *context)
{
	int		result;

	result = 1;
	if (out_out_bounds(row, col, context) == 1 ||
		another_piece_there(row, col, context->board) == 1)
		result = 0;
	return (result);
}


