/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:55:57 by kmira             #+#    #+#             */
/*   Updated: 2020/02/10 21:47:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	int					keep_playing;
	t_filler_context	context;

	init_debug();
	context = init_game_context();

	keep_playing = 1;
	char	buffer[30];
	// while (keep_playing)
	// {
		new_piece_to_be_place(&context);
		debug_out_str(buffer);
		// print_heatmap(&context);
	// }
	return (0);
}
