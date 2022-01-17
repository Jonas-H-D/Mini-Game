/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:27:53 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/14 17:23:47 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE 32

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_ready
{
	int	player;
	int	collect;
	int	exit;
}	t_ready;

typedef struct s_image
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*collect;
	void	*exit;
	void	*score;
}	t_image;

typedef struct s_game
{
	t_vector	size;
	t_vector	point;
	t_vector	player;
	t_image		image;
	char		**map;
	void		*mlx;
	void		*window;
	int			coins;
	int			moves;
}	t_game;

int		error(char *message);
void	*null_error(char *message);
void	ft_get_map(t_game *game, char *file);
int		ft_valid_file(char *file);
int		ft_check_map(t_game *game);
int		ft_close(void);
void	ft_load_image(t_game *game, int img_width, int img_height);
void	ft_draw_image(t_game *game, int y, int x);
int		ft_input(int key, void *param);
void	ft_move_r(t_game *game);
void	ft_move_l(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_d(t_game *game);
char	*ft_itoa(int n);
void	draw_scoreboard(t_game *game, int x, int y);

#endif
