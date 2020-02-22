/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learnread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:44:05 by kmira             #+#    #+#             */
/*   Updated: 2020/02/21 17:48:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	buff[10];

	bzero(buff, sizeof(buff));
	read(STDIN_FILENO, buff, 1);

	read(STDIN_FILENO, buff, 1);
	return (0);
}
