/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:34:03 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 17:30:41 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_image(t_game *game, int y, int x)
{
	game->image.wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/tree.xpm", &x, &y);
	game->image.empty = mlx_xpm_file_to_image(game->mlx,
			"sprites/grass.xpm", &x, &y);
	game->image.collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/chest.xpm", &x, &y);
	game->image.exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/house.xpm", &x, &y);
	game->image.player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &x, &y);
	game->image.score = mlx_xpm_file_to_image(game->mlx,
			"sprites/score.xpm", &x, &y);
}

void	draw_scoreboard(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->image.score, x, y);
	mlx_string_put(game->mlx, game->window, 60, 22, 0x99FFFFFF, "Moves : ");
	mlx_string_put(game->mlx, game->window, 150, 22, 0x99FFFFFF,
		ft_itoa(game->moves));
}

void	ft_draw_image(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.wall, x * IMG_SIZE, y * IMG_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.empty, x * IMG_SIZE, y * IMG_SIZE);
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.collect, x * IMG_SIZE, y * IMG_SIZE);
		game->coins++;
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.exit, x * IMG_SIZE, y * IMG_SIZE);
	else if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->image.player, x * IMG_SIZE, y * IMG_SIZE);
		game->player.x = x;
		game->player.y = y;
	}
	draw_scoreboard(game, 3, 2);
}
