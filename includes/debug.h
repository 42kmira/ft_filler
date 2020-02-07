/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:32:59 by kmira             #+#    #+#             */
/*   Updated: 2020/02/07 05:40:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <fcntl.h>

# define DEBUG_SET 1
# define DEBUG_FILE_PATH "debug_file"

int		debug_fd(int option, int value);
void	init_debug(void);

#endif
