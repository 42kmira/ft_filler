/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:55:57 by kmira             #+#    #+#             */
/*   Updated: 2020/02/07 06:34:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_filler_context filler_context;

	init_debug();
	filler_context = init_game_context();
	debug_out(&filler_context.player_char, 1);
	return (0);
}
