/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_ptr_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:51:48 by kmira             #+#    #+#             */
/*   Updated: 2020/02/19 11:01:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_board_height(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	result = -1;
	ft_bzero(number, sizeof(number));
	read(STDIN_FILENO, &number[i], 1);
	while (i < DIGIT_LEN && number[i] != ' ')
	{
		i++;
		read(STDIN_FILENO, &number[i], 1);
	}
	number[i] = '\0';
	result = ft_atoi(number);
	return (result);
}

int		get_board_width(void)
{
	int		i;
	int		result;
	char	number[DIGIT_LEN];

	i = 0;
	result = -1;
	ft_bzero(number, sizeof(number));
	read(STDIN_FILENO, &number[i], 1);
	while (i < DIGIT_LEN && number[i] != ':')
	{
		i++;
		read(STDIN_FILENO, &number[i], 1);
	}
	number[i] = '\0';
	result = ft_atoi(number);
	return (result);
}
