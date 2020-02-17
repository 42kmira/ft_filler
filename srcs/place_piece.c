/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:38:00 by kmira             #+#    #+#             */
/*   Updated: 2020/02/16 20:40:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_piece(t_filler_context *context, t_piece *piece)
{
	t_piece	*spot;
	t_piece	*iter;
	t_piece	*piece_place;
	int		valid;
	int		row;
	int		col;

	spot = context->player;
	while (spot != NULL)
	{
		//first is 0 0 0 0, second is piece of intersect and
		//last is where verification starts.
		piece_place = piece->next;
		while (piece_place != NULL)
		{
			valid = 1;
			iter = piece->next;
			while (iter != NULL && valid == 1)
			{
				row = spot->row_rel + (iter->row_rel - piece_place->row_rel);
				col = spot->col_rel + (iter->col_rel - piece_place->col_rel);
				if (iter != piece_place && is_valid_placement(row, col, context) == 0)
					valid = 0;
				iter = iter->next;
			}
			if (valid == 1)
				break ;
			piece_place = piece_place->next;
		}
		if (valid == 1)
			break ;
		spot = spot->next;
	}

	ft_putnbr_fd(spot->row_rel - (piece_place)->row_rel, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(spot->col_rel - (piece_place)->col_rel, 1);
	ft_putchar_fd('\n', 1);

	int		row_offset;
	int		col_offset;

	row_offset = spot->row_rel - (piece_place)->row_rel;
	col_offset = spot->col_rel - (piece_place)->col_rel;
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
		if (iter == piece_place)
			iter = iter->next;
		spot->next = iter;

		if (iter != NULL)
		{
			spot = spot->next;
			iter = iter->next;
		}
	}
}

