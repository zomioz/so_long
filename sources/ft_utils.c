/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:45:08 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/21 00:40:23 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nb_lines(t_struct *s_map)
{
	int	x;

	x = 0;
	while (s_map->map[x])
		x++;
	return (x);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	size_t	x;
	size_t	y;

	if (s1)
		x = (ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		x = ft_strlen(s2) + 1;
	dest = ft_calloc(sizeof(char), x);
	if (!(dest))
		return (0);
	y = 0;
	x = 0;
	if (s1)
	{
		while (s1[y] != '\0' && s1)
			dest[x++] = s1[y++];
	}
	y = 0;
	while (s2[y] != '\0')
		dest[x++] = s2[y++];
	if (s1)
		free(s1);
	return (dest);
}

void	ft_free_struct(t_struct *s_map)
{
	int	x;

	x = 0;
	while (s_map->map[x])
	{
		free(s_map->map[x]);
		x++;
	}
	free(s_map->map);
	free(s_map);
}

int	ft_check_collectible(t_struct *s_map)
{
	int	x;
	int	y;
	int	check;

	check = 0;
	x = 0;
	y = 0;
	while (s_map->map[x])
	{
		while (s_map->map[x][y])
		{
			if (s_map->map[x][y] == 'C')
				check++;
			y++;
		}
		y = 0;
		x++;
	}
	return (check);
}

void	ft_find_player(t_struct *s_map)
{
	s_map->p_x = 0;
	s_map->p_y = 0;
	while (s_map->map[s_map->p_x])
	{
		while (s_map->map[s_map->p_x][s_map->p_y])
		{
			if (s_map->map[s_map->p_x][s_map->p_y] == 'P')
				return ;
			s_map->p_y++;
		}
		s_map->p_y = 0;
		s_map->p_x++;
	}
}
