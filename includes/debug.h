/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:32:59 by kmira             #+#    #+#             */
/*   Updated: 2020/02/08 02:00:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <fcntl.h>
# include <unistd.h>

# include "libft.h"
# include "filler.h"

# define DEBUG_SET 1
# define DEBUG_GET 2

# define DEBUG_FILE_PATH "debug_file"

int		debug_fd(int option, int value);
void	init_debug(void);
void	debug_out(void *memory, size_t size);
void	debug_out_str(char *str);
void	debug_out_board(t_filler_context *context);

#endif
