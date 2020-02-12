/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:35:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/11 19:14:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

int		debug_fd(int option, int value)
{
	static int	debug_fd;

	if (option == DEBUG_SET)
		debug_fd = value;
	return (debug_fd);
}

void	init_debug(void)
{
	int	debug_out;

	debug_out = open(DEBUG_FILE_PATH, O_RDWR);
	debug_fd(DEBUG_SET, debug_out);
}

void	debug_out(void *memory, size_t size)
{
	int	out_fd;

	out_fd = debug_fd(DEBUG_GET, 0);
	write(out_fd, memory, size);
}

void	debug_out_str(char *str)
{
	int	size;
	int	out_fd;

	size = ft_strlen(str);
	out_fd = debug_fd(DEBUG_GET, 0);
	debug_out(str, size);
	write(out_fd, "\n", 1);
}

void	debug_out_board(t_filler_context *context)
{
	int	row;

	row = 0;
	while (row < context->board_height)
	{
		debug_out_str(context->board[row]);
		row++;
	}
}

// void	debug_out_piece(t_filler_context *context)
// {
// 	char	*string;
// 	t_piece	*iter;

// 	iter = context->player;
// 	while (iter != NULL)
// 	{
// 		string = asprintf("");
// 		iter = iter->next;
// 	}
// }
