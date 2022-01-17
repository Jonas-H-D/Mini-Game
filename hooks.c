/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:52:36 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 17:21:17 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	printf("/// game->coins == %d", game->coins);
	printf("*** Key Pressed = %d\n", key);
	if (key == 2)
		ft_move_r(game);
	if (key == 0)
		ft_move_l(game);
	if (key == 13)
		ft_move_up(game);
	if (key == 1)
		ft_move_d(game);
	if (key == 53)
		exit(0);
	game->moves++;
	printf("moves = %s\n", ft_itoa(game->moves));
	draw_scoreboard(game, 3, 2);
	return (0);
}
