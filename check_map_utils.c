/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:18:37 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 15:29:58 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_type(char *s, char *end)
{
	int	s_len;
	int	end_len;

	s_len = ft_strlen(s);
	end_len = ft_strlen(end);
	if (s_len <= end_len)
		return (0);
	s += s_len - end_len;
	while (*s)
	{
		if (*s != *end)
			return (0);
		s++;
		end++;
	}
	return (1);
}

int	ft_valid_file(char *file)
{
	if (!ft_file_type(file, ".ber"))
		return (0);
	return (1);
}

void	ft_init_ready(t_ready *ready)
{
	ready->player = 0;
	ready->collect = 0;
	ready->exit = 0;
}
