/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:55:57 by kmira             #+#    #+#             */
/*   Updated: 2020/02/22 15:38:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler_context	context;
	char				buff[50];
	t_piece				*piece;

	context = init_game_context();
	while (errno != EBADMSG)
	{
		update_heatmap(&context);
		print_heatmap(&context);
		piece = new_piece_to_place();
		place_piece(&context, piece, context.player);
		if (errno != EBADMSG)
		{
			ft_bzero(buff, sizeof(buff));
			read(STDIN_FILENO, buff, 8);
			get_board_height();
			get_board_width();
			update_board(&context);
		}
	}
	deconstruct_filler_context(&context);
	system("leaks kmira.filler > leaks.txt");
}
