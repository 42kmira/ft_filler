/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:29:02 by kmira             #+#    #+#             */
/*   Updated: 2020/02/10 22:00:45 by kmira            ###   ########.fr       */
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
	{
		*piece_head = make_piece(row, col, row, col);
	}
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
		result[row] = malloc(sizeof(**result) * (piece_width + 1));
		read(STDIN_FILENO, result[row], piece_width + 1);
		result[row][piece_width + 1] = '\0';
		debug_out_str(result[row]);
		row++;
	}
	result[row] = NULL;
	return (result);
}

t_piece	*new_piece_to_be_place(t_filler_context *context)
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
	debug_out_str(buff);
	piece_height = ft_atoi(buff);

	i = 0;
	read(STDIN_FILENO, buff, 1);
	while (buff[i] != ':')
	{
		i++;
		read(STDIN_FILENO, &buff[i], 1);
	}
	buff[i] = '\0';
	debug_out_str(buff);
	piece_width = ft_atoi(buff);

	get_piece_board(piece_height, piece_width);
	(void)context;
	return (NULL);
}
