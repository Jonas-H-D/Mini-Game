/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:40:12 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 15:50:18 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}
