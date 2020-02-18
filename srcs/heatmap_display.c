/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:30:12 by kmira             #+#    #+#             */
/*   Updated: 2020/02/18 15:21:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define ANSI_RESET "\033[0m"

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
			if (ft_tolower((context->board)[row][col]) == context->player_char)
				dprintf(STDERR_FILENO, BOLDCYAN"%2c"ANSI_RESET, context->player_char);
			else if ((context->board)[row][col] != '.')
				dprintf(STDERR_FILENO, RED"%2c"ANSI_RESET, ('O' | 'X') ^ (context->player_char ^ ('O' & 'X')));
			else
				dprintf(STDERR_FILENO, "%s%2d", color, (context->heatmap)[row][col]);
		}
		// dprintf(STDERR_FILENO, ANSI_RESET"\n");
		dprintf(STDERR_FILENO, ANSI_RESET"\n");
	}
	dprintf(STDERR_FILENO, "\033[%dA", (context->board_height));

	int i;

	i = 0;
	while (i < 10000000)
		i++;
}
