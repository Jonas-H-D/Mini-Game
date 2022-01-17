/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:01:27 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 16:53:24 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_file_type(char *s, char *end);
int		ft_valid_file(char *file);
void	ft_init_ready(t_ready *ready);

int	ft_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'E'
		|| c == 'P' || c == 'C')
		return (1);
	return (0);
}

void	ft_update_ready(char c, t_ready *ready)
{
	if (c == 'E')
		ready->exit++;
	else if (c == 'P')
		ready->player++;
	else if (c == 'C')
		ready->collect++;
}

int	ft_unique_char(t_ready *ready)
{
	if (ready->player != 1)
		return (error("you need 1 player"));
	if (ready->collect == 0)
		return (error("you need at least 1 collectable"));
	if (ready->exit == 0)
		return (error("you need at least 1 exit"));
	return (1);
}

int	ft_check_map(t_game	*game)
{
	t_ready	ready;
	int		y;
	int		x;

	y = 0;
	ft_init_ready(&ready);
	while (y < game->size.y - 1)
	{
		if (ft_strlen(game->map[y]) != game->size.x)
			return (error("map must be rectangular"));
		x = 0;
		while (x < game->size.x - 1)
		{
			if (!ft_valid_char(game->map[y][x]))
				return (error("non valid char"));
			ft_update_ready(game->map[y][x], &ready);
			x++;
		}
		y++;
	}
	if (!ft_unique_char(&ready))
		return (error("use a valid map"));
	return (1);
}
