/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:38:00 by kmira             #+#    #+#             */
/*   Updated: 2020/02/18 15:25:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		write_move(t_piece *max_spot, t_piece *max_piece_place)
{
	if (max_piece_place != NULL && max_spot != NULL)
	{
		ft_putnbr_fd(max_spot->row_rel - (max_piece_place)->row_rel, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(max_spot->col_rel - (max_piece_place)->col_rel, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		write(1, "0 0\n", 4);
}

int		place_piece(t_filler_context *context, t_piece *piece)
{
	t_piece	*spot;
	t_piece	*iter;
	t_piece	*piece_place;
	int		valid;
	int		row;
	int		col;

	t_piece	*max_spot;
	t_piece	*max_piece_place;
	int		curr_sum;
	int		max_sum;

	max_spot = NULL;
	max_piece_place = NULL;
	max_sum = -2147483648;

	spot = context->player;
	while (spot != NULL)
	{
		//first is 0 0 0 0, second is piece of intersect and
		//last is where verification starts.
		piece_place = piece->next;
		while (piece_place != NULL)
		{
			valid = 1;
			curr_sum = 0;
			iter = piece->next;
			while (iter != NULL && valid == 1)
			{
				row = spot->row_rel + (iter->row_rel - piece_place->row_rel);
				col = spot->col_rel + (iter->col_rel - piece_place->col_rel);
				if (iter != piece_place && valid_placement(row, col, context) == 0)
					valid = 0;
				else
					curr_sum += (context->heatmap)[row][col];
				iter = iter->next;
			}
			if (valid == 1 && max_sum < curr_sum)
			{
				max_sum = curr_sum;
				max_spot = spot;
				max_piece_place = piece_place;
			}
			piece_place = piece_place->next;
		}
		spot = spot->next;
	}

	write_move(max_spot, max_piece_place);
	if (max_spot == NULL || max_piece_place == NULL)
		return (0);

	int		row_offset;
	int		col_offset;

	row_offset = max_spot->row_rel - (max_piece_place)->row_rel;
	col_offset = max_spot->col_rel - (max_piece_place)->col_rel;
	iter = piece->next;
	while (iter != NULL)
	{
		iter->row_rel += row_offset;
		iter->col_rel += col_offset;
		dprintf(debug_fd(DEBUG_GET, 0), "ROW: %d COL: %d\n", iter->row_rel, iter->col_rel);
		iter = iter->next;
	}
	iter = piece->next;
	spot = context->player;
	while (spot->next != NULL)
		spot = spot->next;
	while (iter != NULL)
	{
		if (iter == max_piece_place)
			iter = iter->next;
		spot->next = iter;

		if (iter != NULL)
		{
			spot = spot->next;
			iter = iter->next;
		}
	}
	return (1);
}

