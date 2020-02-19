/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 01:56:57 by kmira             #+#    #+#             */
/*   Updated: 2020/02/18 16:52:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>

# include "libft.h"
# include "filler_structs.h"
# include "color.h"

# include "debug.h"

# define P1 'o'
# define P2 'x'

# define DIGIT_LEN 20

t_filler_context	init_game_context(void);
void				update_board(t_filler_context *context);
void				move_stdin_ptr_to_board_size(void);
int					get_board_height(void);
int					get_board_width(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILES: heatmap_color.c heatmap_display.c heatmap.c
*/

int					get_red(int num, int max);
int					get_blue(int num, int max);
int					get_green(int num, int max);

char				*color_code(uint8_t red, uint8_t green, uint8_t blue);

void				print_heatmap(t_filler_context *context);

int					**create_heatamp(int height, int width);
void				update_heatmap(t_filler_context *context);
void				fill_heat_map(int **heat_map, int height, int width,
								int current, t_filler_context *context);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILES: get_piece.c
*/

t_piece				*new_piece_to_place(void);
void				append_piece(t_piece **piece_head, int row, int col);
int					place_piece(t_filler_context *context, t_piece *piece);
void				free_piece(t_piece *piece);

int					valid_placement(int row, int col, t_filler_context *contex);

#endif
