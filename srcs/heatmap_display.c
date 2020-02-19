/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:30:12 by kmira             #+#    #+#             */
/*   Updated: 2020/02/18 22:30:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define ANSI_RESET "\033[0m"

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
		dprintf(STDERR_FILENO, BOLDCYAN"%2c", context->player_char);
	else if (spot_char == enemy_char)
		dprintf(STDERR_FILENO, RED"%2c", enemy_char);
	else
		dprintf(STDERR_FILENO, "%s%2d", color, (context->heatmap)[row][col]);
}

void	print_heatmap(t_filler_context *context)
{
	int		row;
	int		col;
	int		num;
	int		max;
	char	*color;

	if (context->board_height < context->board_width)
		max = context->board_width;
	else
		max = context->board_height;
	row = -1;
	max = max / 2;
	while (++row < context->board_height)
	{
		col = -1;
		while (++col < context->board_width)
		{
			num = (context->heatmap)[row][col] - max;
			color = color_code(get_red(num, max), get_green(num, max), get_blue(num, max));
			print_heatmap_spot(context, row, col, color);
		}
		dprintf(STDERR_FILENO, ANSI_RESET"\n");
	}
	dprintf(STDERR_FILENO, "\033[%dA", (context->board_height));
}
