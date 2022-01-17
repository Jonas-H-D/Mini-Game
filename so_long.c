/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:48:52 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/17 16:01:02 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	ft_load_image(game, 0, 0);
	while (y <= game->size.y - 2)
	{
		x = 0;
		while (x <= game->size.x - 2)
		{
			ft_draw_image(game, y, x);
			x++;
		}
		y++;
	}
}

int	init_game(t_game *game, char **file)
{
	ft_get_map(game, *file);
	if (!ft_check_map(game))
		return (error("check map not validated"));
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, IMG_SIZE * (game->size.x - 1),
			IMG_SIZE * (game->size.y - 1), "The best game");
	if (game->mlx == NULL || game->window == NULL)
		return (error("Window opening issue"));
	draw_map(game);
	printf("player y=%d & x=%d\n", game->player.y, game->player.x);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error("expecting 1 map as argument"));
	if (!ft_valid_file(argv[1]))
		return (error("expecting .ber file type"));
	if (!init_game(&game, &argv[1]))
		return (error("init failed"));
	mlx_hook(game.window, 17, 0, &ft_close, 0);
	mlx_key_hook(game.window, *ft_input, &game);
	mlx_loop(game.mlx);
	free (game.map);
	return (0);
}
