/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:29:02 by kmira             #+#    #+#             */
/*   Updated: 2020/02/16 19:10:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece	*make_piece(int row_origin, int col_origin, int row, int col)
{
	t_piece	*result;

	result = malloc(sizeof(*result));
	result->row_origin = row_origin;
	result->col_origin = col_origin;

	result->row_rel = row;
	result->col_rel = col;

	result->next = NULL;

	return (result);
}

void	append_piece(t_piece **piece_head, int row, int col)
{
	int		row_origin;
	int		col_origin;
	t_piece	*iter;

	if (*piece_head == NULL)
		*piece_head = make_piece(row, col, row, col);
	else
	{
		iter = *piece_head;
		row_origin = iter->row_origin;
		col_origin = iter->col_origin;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = make_piece(row_origin, col_origin, row, col);
	}
}

#define PIECE_ 6

char	**get_piece_board(int piece_height, int piece_width)
{
	int		row;
	char	**result;

	row = 0;
	result = malloc(sizeof(*result) * (piece_height + 1));
	while (row < piece_height)
	{
		result[row] = malloc(sizeof(**result) * (piece_width + 10));
		ft_bzero(result[row], sizeof(**result) * (piece_width + 10));
		read(STDIN_FILENO, result[row], 1);
		read(STDIN_FILENO, result[row], piece_width);
		result[row][piece_width] = '\0';
		row++;
	}
	result[row] = NULL;
	read(STDIN_FILENO, &row, 1);
	return (result);
}

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

t_piece	*new_piece_to_be_place(void)
{
	int		i;
	int		piece_height;
	int		piece_width;
	char	buff[DIGIT_LEN];

	read(STDIN_FILENO, buff, PIECE_);
	read(STDIN_FILENO, buff, 1);
	i = 0;
	while (buff[i] != ' ')
	{
		i++;
		read(STDIN_FILENO, &buff[i], 1);
	}
	buff[i] = '\0';
	piece_height = ft_atoi(buff);

	i = 0;
	read(STDIN_FILENO, buff, 1);
	while (buff[i] != ':')
	{
		i++;
		read(STDIN_FILENO, &buff[i], 1);
	}
	buff[i] = '\0';
	piece_width = ft_atoi(buff);

	char **piece_board;

	piece_board = get_piece_board(piece_height, piece_width);
	t_piece	*piece;
	int	row;
	int	col;

	row = 0;
	piece = make_piece(0, 0, 0, 0);
	while (row < piece_height)
	{
		col = 0;
		while (col < piece_width)
		{
			if ((piece_board)[row][col] == '*')
				append_piece(&piece, row, col);
			col++;
		}
		row++;
	}
	return (piece);
}

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

