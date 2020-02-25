/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_ptr_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:51:48 by kmira             #+#    #+#             */
/*   Updated: 2020/02/24 16:32:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_num(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	read(STDIN_FILENO, &number[i], 1);
	while (i < DIGIT_LEN && ft_isdigit(number[i]))
	{
		i++;
		read(STDIN_FILENO, &number[i], 1);
	}
	result = ft_atoi(number);
	return (result);
}

int		get_board_height(void)
{
	int		result;

	result = read_num();
	return (result);
}

int		get_board_width(void)
{
	int		result;

	result = read_num();
	return (result);
}
