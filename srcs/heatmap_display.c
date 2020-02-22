/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:30:12 by kmira             #+#    #+#             */
/*   Updated: 2020/02/22 15:54:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_heatmap_spot(t_filler_context *context,
							int row, int col, char *color)
{
	char	spot_char;
	char	enemy_char;

	if (context->player_char == P1)
		enemy_char = P2;
	else
		enemy_char = P1;
	spot_char = ft_tolower((context->board)[row][col]);
	if (spot_char == context->player_char)
	{
		write(STDERR_FILENO, BOLDCYAN, 9);
		write(STDERR_FILENO, &context->player_char, 1);
	}
	else if (spot_char == enemy_char)
	{
		write(STDERR_FILENO, ANSI_RESET""RED, 9);
		write(STDERR_FILENO, &enemy_char, 1);
	}
	else
	{
		ft_putstr_fd(color, STDERR_FILENO);
		write(STDERR_FILENO, "#", 1);
	}
}

void	move_cursor_up(int amount)
{
	write(STDERR_FILENO, "\n\033[", 3);
	ft_putnbr_fd(amount, STDERR_FILENO);
	write(STDERR_FILENO, "A"ANSI_RESET, 5);
}

void	print_heatmap(t_filler_context *context)
{
	int		row;
	int		col;
	int		num;
	int		max;
	char	result[50];

	if (context->board_height > context->board_width)
		max = context->board_height / 2;
	else
		max = context->board_width / 2;
	row = -1;
	while (++row < context->board_height)
	{
		col = -1;
		write(STDERR_FILENO, ANSI_RESET"\n    ", 9);
		while (++col < context->board_width)
		{
			num = (context->heatmap)[row][col] - max;
			print_heatmap_spot(context, row, col,
					colour_code(get_r(num, max),
								get_g(num, max),
								get_b(num, max), result));
		}
	}
	move_cursor_up((context->board_height) + 1);
}
