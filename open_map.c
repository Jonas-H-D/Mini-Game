/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:33:42 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/10 17:21:28 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_linecount(char *file)
{
	char	c;
	int		read_bytes;
	int		line_count;
	int		fd;

	fd = open (file, O_RDONLY);
	if (!fd)
		return (-1);
	line_count = 1;
	while (fd)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 1)
			return (-1);
		if (c == '\n')
			line_count++;
	}
	close (fd);
	return (line_count);
}

char	**ft_alloc_lines(char *file, t_game *game)
{
	char	**map;
	int		linecount;

	linecount = ft_file_linecount(file);
	if (linecount <= 0)
		return (NULL);
	game->size.y = linecount;
	map = malloc(sizeof(char *) * linecount + 1);
	if (map == NULL)
		return (null_error("malloc error on ft_alloc_lines"));
	return (map);
}

void	ft_get_map(t_game *game, char *file)
{
	int		fd;
	int		i;

	i = 0;
	game->map = ft_alloc_lines(file, game);
	fd = open (file, O_RDONLY);
	while (fd)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
	}
	game->size.x = ft_strlen(game->map[0]);
	game->map[i] = 0;
	close (fd);
}
