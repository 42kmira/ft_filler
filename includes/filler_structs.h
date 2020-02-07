/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:40:56 by kmira             #+#    #+#             */
/*   Updated: 2020/02/07 05:43:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_STRUCTS_H
# define FILLER_STRUCTS_H

typedef struct	s_filler_context
{
	int		player_no;
	char	player_char;
	int		board_width;
	int		board_height;
	char	**board;
}				t_filler_context;

#endif
