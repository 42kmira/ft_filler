/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:47:45 by kmira             #+#    #+#             */
/*   Updated: 2020/02/12 13:41:56 by kmira            ###   ########.fr       */
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
		read(STDIN_FILENO, buff, 1);
	read(STDIN_FILENO, buff, 1);

	ft_bzero(buff, sizeof(buff));
	read(STDIN_FILENO, buff, PLATEAU_);
}

int		get_board_height(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	result = -1;
	ft_bzero(number, sizeof(number));
	read(STDIN_FILENO, &number[i], 1);
	while (i < DIGIT_LEN && number[i] != ' ')
	{
		i++;
		read(STDIN_FILENO, &number[i], 1);
	}
	number[i] = '\0';
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
	read(STDIN_FILENO, &number[i], 1);
	while (i < DIGIT_LEN &&  number[i] != ':')
	{
		i++;
		read(STDIN_FILENO, &number[i], 1);
	}
	number[i] = '\0';
	result = ft_atoi(number);
	return (result);
}

void			init_board(t_filler_context *context)
{
	int		i;

	i = 0;
	context->board = malloc(sizeof(*context->board) * (context->board_height + 1));
	while (i < context->board_height)
	{
		context->board[i] = malloc(sizeof(*(context->board[i])) * (context->board_width + 1));
		context->board[i][context->board_width + 1] = '\0';
		i++;
	}
	context->board[i] = NULL;
}

void				get_player(t_filler_context *context)
{
	int	row;
	int	col;

	row = 0;
	context->player = NULL;
	while (row < context->board_height)
	{
		col = 0;
		while (col < context->board_width)
		{
			if (ft_tolower((context->board)[row][col]) == context->player_char)
				append_piece(&context->player, row, col);
			col++;
		}
		row++;
	}
}

t_filler_context	init_game_context(void)
{
	t_filler_context	filler_context;

	filler_context.player_no = get_player_no();
	if (filler_context.player_no == 1)
		filler_context.player_char = P1;
	else
		filler_context.player_char = P2;
	move_stdin_ptr_to_board_size();
	filler_context.board_height = get_board_height();
	filler_context.board_width = get_board_width();
	init_board(&filler_context);
	update_board(&filler_context);
	filler_context.heatmap = create_heatamp(filler_context.board_height, filler_context.board_width);
	update_heatmap(&filler_context);
	get_player(&filler_context);
	return (filler_context);
}
