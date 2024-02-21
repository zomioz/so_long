/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:44:27 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 19:50:24 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_tab(char *argv)
{
	int		fd;
	char	*tempo;
	char	*stock;

	stock = NULL;
	tempo = NULL;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		tempo = get_next_line(fd);
		if (tempo == NULL)
			break ;
		stock = ft_strjoin_free(stock, tempo);
		free(tempo);
		tempo = NULL;
	}
	close(fd);
	if (stock == 0 || ft_check_inside(stock) == 0)
	{
		ft_printf("Please enter a valid map\n");
		return (0);
	}
	if (ft_start_map(stock) == 0)
		return (0);
	return (1);
}

int	ft_start_map(char *stock)
{
	t_struct	*s_map;
	int			x;

	s_map = malloc(sizeof(t_struct));
	x = 0;
	s_map->map = ft_split(stock, '\n');
	free(stock);
	if (ft_checker_length(s_map) == 0
		|| ft_checker_outside_tb(s_map) == 0
		|| ft_checker_outside_lr(s_map) == 0)
	{
		ft_printf("Map isn't rectangular or isn't closed!\n");
		ft_free_struct(s_map);
		return (0);
	}
	if (ft_start_file(s_map) == 0)
	{
		ft_printf("map isn't valid!\n");
		ft_free_struct(s_map);
		return (0);
	}
	ft_go_map(s_map);
	return (1);
}
