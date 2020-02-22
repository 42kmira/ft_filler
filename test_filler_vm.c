/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_filler_vm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:58:21 by kmira             #+#    #+#             */
/*   Updated: 2020/02/21 18:08:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/color.h"

#define STOP 500

int	main(void)
{
	int	i;

	i = 0;
	while (i < STOP)
	{
		printf(PURPLE"Start of test %d"COLOR_RESET"\n", i);
		system("make play");
		printf(PURPLE"END of test %d"COLOR_RESET"\n", i);
		i++;
	}
	return (0);
}
