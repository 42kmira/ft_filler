/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:47:45 by kmira             #+#    #+#             */
/*   Updated: 2020/02/07 06:40:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

# define $$$_EXEC_P 10

int		get_player_no(void)
{
	int		result;
	char	buff[$$$_EXEC_P + 1];

	result = -1;
	ft_bzero(buff, sizeof(buff));
	read(STDIN_FILENO, buff, $$$_EXEC_P);
	ft_bzero(buff, sizeof(buff));
	read(STDIN_FILENO, buff, 1);
	result = ft_atoi(buff);
	return (result);
}

#define PLATEAU_ 8

void	move_stdin_ptr_to_board_size(void)
{
	char	buff[PLATEAU_ + 1];

	ft_bzero(buff, sizeof(buff));
	while (buff[0] != ']')
	{
		read(STDIN_FILENO, buff, 1);
		debug_out(buff, 1);
	}
	read(STDIN_FILENO, buff, 1);
	ft_bzero(buff, sizeof(buff));
	read(STDIN_FILENO, buff, PLATEAU_ + 1);
	debug_out_str(buff);
}

#define DIGIT_LEN 20

int		get_board_height(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	result = -1;
	ft_bzero(number, sizeof(number));
	while (number[i] != ' ')
	{
		read(STDIN_FILENO, &number[i], 1);
		i++;
	}
	debug_out_str("WRITING HIEGHT\n");
	debug_out_str(number);
	result = ft_atoi(number);
	return (result);
}

int		get_board_width(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	result = -1;
	ft_bzero(number, sizeof(number));
	while (number[i] != '\n')
	{
		read(STDIN_FILENO, &number[i], 1);
		i++;
	}
	debug_out_str("WRITING WIDTH\n");
	debug_out_str(number);
	result = ft_atoi(number);
	return (result);
}

t_filler_context	init_game_context(void)
{
	int					i;
	t_filler_context	filler_context;

	filler_context.player_no = get_player_no();
	if (filler_context.player_no == 1)
		filler_context.player_char = 'O';
	else
		filler_context.player_char = 'X';
	move_stdin_ptr_to_board_size();
	filler_context.board_height = get_board_height();
	filler_context.board_width = get_board_width();
	filler_context.board = malloc(sizeof(*filler_context.board)
							* (filler_context.board_height + 1));
	ft_bzero(filler_context.board, sizeof(*filler_context.board)
							* (filler_context.board_height + 1));
	i = 0;
	while (i < filler_context.board_height)
	{
		filler_context.board[i] = malloc(sizeof(*(filler_context.board[i]))
										* (filler_context.board_width + 1));
		ft_bzero(filler_context.board[i], sizeof(*(filler_context.board[i]))
										* (filler_context.board_width + 1));
		i++;
	}
	return (filler_context);
}
