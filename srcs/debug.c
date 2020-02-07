/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:35:31 by kmira             #+#    #+#             */
/*   Updated: 2020/02/07 05:38:46 by kmira            ###   ########.fr       */
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
