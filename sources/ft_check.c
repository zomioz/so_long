/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:40:36 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 18:16:48 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *argv)
{
	int	x;
	int	fd;

	fd = -1;
	x = 0;
	while (argv[x] != '\0')
		x++;
	if (argv[x - 1] == 'r' && argv[x - 2] == 'e'
		&& argv[x - 3] == 'b' && argv[x - 4] == '.')
	{
		fd = open(argv, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			return (1);
		}
	}
	return (0);
}

int	ft_check_inside(char *str)
{
	int	x;
	int	player;
	int	collectibles;
	int	exit;

	x = 0;
	collectibles = 0;
	player = 0;
	exit = 0;
	while (str[x])
	{
		if (str[x] == 'C')
			collectibles++;
		if (str[x] == 'P')
			player++;
		if (str[x] == 'E')
			exit++;
		if (str[x] != '1' && str[x] != '0' && str[x] != 'C'
			&& str[x] != 'P' && str[x] != 'E' && str[x] != '\n')
			return (0);
		x++;
	}
	if (collectibles > 0 && player == 1 && exit == 1)
		return (1);
	return (0);
}

int	ft_checker_outside_tb(t_struct *s_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s_map->map[y])
		y++;
	y = y - 1;
	while (s_map->map[0][x])
	{
		if (s_map->map[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (s_map->map[y][x])
	{
		if (s_map->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_checker_outside_lr(t_struct *s_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s_map->map[0][y])
		y++;
	y = y - 1;
	while (s_map->map[x] && s_map->map[x][0])
	{
		if (s_map->map[x][0] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (s_map->map[x] && s_map->map[x][y])
	{
		if (s_map->map[x][y] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_checker_length(t_struct *s_map)
{
	int	x;
	int	y;
	int	length;

	x = 0;
	y = 0;
	length = ft_strlen(s_map->map[x]);
	while (s_map->map[x])
	{
		while (s_map->map[x][y])
		{
			y++;
		}
		if (y != length)
			return (0);
		y = 0;
		x++;
	}
	return (1);
}
