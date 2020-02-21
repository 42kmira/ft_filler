/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:38:00 by kmira             #+#    #+#             */
/*   Updated: 2020/02/20 16:53:04 by kmira            ###   ########.fr       */
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

void	correct_piece(t_piece *max_spot, t_piece *max_piece,
						t_piece *root, t_piece **player)
{
	int		row_offset;
	int		col_offset;
	t_piece	*iter;

	if (max_spot == NULL || max_piece == NULL)
		return ;
	row_offset = max_spot->row_rel - (max_piece)->row_rel;
	col_offset = max_spot->col_rel - (max_piece)->col_rel;
	iter = root;
	while (iter != NULL)
	{
		iter->row_rel += row_offset;
		iter->col_rel += col_offset;
		iter = iter->next;
	}
	iter = *player;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = root->next;
}

void	write_move(t_piece *max_spot, t_piece *max_piece_place)
{
	if (max_piece_place != NULL && max_spot != NULL)
	{
		ft_putnbr_fd(max_spot->row_rel - (max_piece_place)->row_rel, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(max_spot->col_rel - (max_piece_place)->col_rel, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		write(1, "0 0\n", 4);
		errno = EBADMSG;
	}
}

void	place_piece(t_filler_context *context,
						t_piece *piece, t_piece *player)
{
	t_piece	*piece_place;
	t_piece	*max_spot;
	t_piece	*max_piece_place;
	int		max_sum;

	max_spot = NULL;
	max_sum = INT_MIN;
	max_piece_place = NULL;
	while (player != NULL)
	{
		piece_place = piece->next;
		while (piece_place != NULL)
		{
			if (max_sum < get_sum(piece->next, context, piece_place, player))
			{
				max_sum = get_sum(piece->next, context, piece_place, player);
				max_spot = player;
				max_piece_place = piece_place;
			}
			piece_place = piece_place->next;
		}
		player = player->next;
	}
	write_move(max_spot, max_piece_place);
	correct_piece(max_spot, max_piece_place, piece, &context->player);
}
