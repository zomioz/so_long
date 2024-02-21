/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:22:40 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 19:40:44 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_struct	*ft_dupli_map(t_struct *s_map)
{
	t_struct	*copy;
	int			i;

	i = 0;
	copy = malloc(sizeof(t_struct));
	while (s_map->map[i])
		i++;
	copy->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (1)
	{
		if (s_map->map[i])
			copy->map[i] = ft_strdup(s_map->map[i]);
		else
		{
			copy->map[i] = NULL;
			break ;
		}
		i++;
	}
	return (copy);
}

static int	ft_checker_file(t_struct *copy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (copy->map[x])
	{
		while (copy->map[x][y])
		{
			if (copy->map[x][y] != '1' && copy->map[x][y] != 'Z'
				&& copy->map[x][y] != '0')
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

static void	ft_flood_file(t_struct *copy, int x, int y)
{
	if (copy->map[x][y] != '1' && copy->map[x][y] != 'Z')
	{
		copy->map[x][y] = 'Z';
		ft_flood_file(copy, (x + 1), y);
		ft_flood_file(copy, x, (y + 1));
		ft_flood_file(copy, (x - 1), y);
		ft_flood_file(copy, x, (y - 1));
	}
}

int	ft_start_file(t_struct *s_map)
{
	int			x;
	int			y;
	t_struct	*copy;

	copy = ft_dupli_map(s_map);
	x = 0;
	y = 0;
	while (s_map->map[x])
	{
		while (s_map->map[x][y] != 'P' && s_map->map[x][y] != '\0')
			y++;
		if (s_map->map[x][y] == 'P')
		{
			ft_flood_file(copy, x, y);
			if (ft_checker_file(copy) == 0)
			{
				ft_free_struct(copy);
				return (0);
			}
		}
		y = 0;
		x++;
	}
	ft_free_struct(copy);
	return (1);
}
