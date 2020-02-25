/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 02:51:52 by kmira             #+#    #+#             */
/*   Updated: 2020/02/24 16:58:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** We can calc the number of digits a number should have and make the one read.
** Also make a function to read the header, that woud be good.
*/

void				update_board(t_filler_context *context)
{
	int		row;
	int		col;
	char	*buffer;

	row = 0;
	buffer = malloc(sizeof(*buffer) * (context->board_width + 1));
	read(STDIN_FILENO, buffer, 5);
	read(STDIN_FILENO, buffer, context->board_width + 1);
	while (row < context->board_height)
	{
		read(STDIN_FILENO, buffer, 3);
		read(STDIN_FILENO, buffer, 1);
		while (buffer[0] != ' ')
			read(STDIN_FILENO, buffer, 1);
		ft_bzero(buffer, sizeof(*buffer) * (context->board_width + 1));
		col = 0;
		while (col < context->board_width)
		{
			read(STDIN_FILENO, &buffer[col], 1);
			col++;
		}
		// read(STDIN_FILENO, buffer, context->board_width);
		ft_strncpy(context->board[row], buffer, context->board_width);
		read(STDIN_FILENO, buffer, 1);
		row++;
	}
	free(buffer);
}

/*
** The other way is to read the entire map in one go and then
** do compacting methods to split up the map.
*/
