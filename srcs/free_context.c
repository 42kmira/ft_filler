/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:05:19 by kmira             #+#    #+#             */
/*   Updated: 2020/02/22 15:26:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(t_piece *piece)
{
	t_piece	*iter;
	t_piece	*release;

	iter = piece;
	while (iter != NULL)
	{
		release = iter;
		iter = iter->next;
		free(release);
	}
}

void	free_boards(t_filler_context *context)
{
	int	row;

	row = 0;
	while (row < context->board_height)
	{
		free(context->board[row]);
		free(context->heatmap[row]);
		context->board[row] = NULL;
		context->heatmap[row] = NULL;
		row++;
	}
	free(context->board);
	context->board = NULL;
	free(context->heatmap);
	context->heatmap = NULL;
}

void	free_piece_board(char **piece_board, int piece_height)
{
	int	row;

	row = 0;
	while (row < piece_height)
	{
		free(piece_board[row]);
		piece_board[row] = NULL;
		row++;
	}
	free(piece_board);
}

void	deconstruct_filler_context(t_filler_context *context)
{
	free_piece(context->player);
	free_boards(context);
}
