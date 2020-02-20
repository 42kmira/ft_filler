/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:55:57 by kmira             #+#    #+#             */
/*   Updated: 2020/02/20 12:58:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	int					keep_playing;
	t_filler_context	context;
	char				buff[50];
	t_piece				*piece;

	init_debug();
	context = init_game_context();
	keep_playing = 1;
	while (keep_playing)
	{
		debug_out_str("START\n");
		update_heatmap(&context);
		print_heatmap(&context);
		piece = new_piece_to_place();
		keep_playing = place_piece(&context, piece);
		if (keep_playing == 1)
		{
			ft_bzero(buff, sizeof(buff));
			read(STDIN_FILENO, buff, 8);
			get_board_height();
			get_board_width();
			update_board(&context);
		}
		debug_out_str("END\n");
	}
	debug_out_str("GAME FINISHED\n");
}
