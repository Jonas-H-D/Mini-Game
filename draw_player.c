/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:53:00 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 17:25:11 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_r(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		if (game->map[game->player.y][game->player.x + 1] == 'E'
				&& game->coins != 0)
			return ;
		if (game->map[game->player.y][game->player.x + 1] == 'E'
				&& game->coins == 0)
			exit (0);
		if (game->map[game->player.y][game->player.x + 1] == 'C')
		{
			game->coins--;
			game->map[game->player.y][game->player.x + 1] = '0';
		}
		game->player.x++;
		mlx_put_image_to_window(game->mlx, game->window, game->image.player,
			game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
			(game->player.x - 1) * IMG_SIZE, game->player.y * IMG_SIZE);
	}
}

void	ft_move_l(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		if (game->map[game->player.y][game->player.x - 1] == 'E'
				&& game->coins != 0)
			return ;
		if (game->map[game->player.y][game->player.x - 1] == 'E'
				&& game->coins == 0)
			exit (0);
		if (game->map[game->player.y][game->player.x - 1] == 'C')
		{
			game->coins--;
			game->map[game->player.y][game->player.x - 1] = '0';
		}
		game->player.x--;
		mlx_put_image_to_window(game->mlx, game->window, game->image.player,
			game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
			(game->player.x + 1) * IMG_SIZE, game->player.y * IMG_SIZE);
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		if (game->map[game->player.y - 1][game->player.x] == 'E'
			&& game->coins != 0)
			return ;
		if (game->map[game->player.y - 1][game->player.x] == 'E'
			&& game->coins == 0)
			exit (0);
		if (game->map[game->player.y - 1][game->player.x] == 'C')
		{
			game->coins--;
			game->map[game->player.y - 1][game->player.x] = '0';
		}
		game->player.y--;
		mlx_put_image_to_window(game->mlx, game->window, game->image.player,
			game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
			game->player.x * IMG_SIZE, (game->player.y + 1) * IMG_SIZE);
	}
}

void	ft_move_d(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		if (game->map[game->player.y + 1][game->player.x] == 'E'
				&& game->coins != 0)
			return ;
		if (game->map[game->player.y + 1][game->player.x] == 'E'
				&& game->coins == 0)
			exit (0);
		if (game->map[game->player.y + 1][game->player.x] == 'C')
		{
			game->coins--;
			game->map[game->player.y + 1][game->player.x] = '0';
		}
		game->player.y++;
		mlx_put_image_to_window(game->mlx, game->window, game->image.player,
			game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
			game->player.x * IMG_SIZE, (game->player.y - 1) * IMG_SIZE);
	}
}
