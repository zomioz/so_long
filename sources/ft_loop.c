/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:41:00 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/21 01:01:23 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_hook(int event, void *param)
{
	t_struct	*s_map;

	s_map = (t_struct *)param;
	if (event == 0)
		mlx_loop_end(s_map->m);
	return (0);
}

int	key_hook(int key, void *param)
{
	static int	plays;
	t_struct	*s_map;

	if (!plays)
		plays = 1;
	s_map = (t_struct *)param;
	if (key == 41)
		mlx_loop_end(s_map->m);
	if (key == 26)
		ft_moove_up(s_map);
	if (key == 22)
		ft_moove_down(s_map);
	if (key == 4)
		ft_moove_left(s_map);
	if (key == 7)
		ft_moove_right(s_map);
	ft_printf("number of plays : %d\n", plays);
	plays++;
	return (0);
}

void	ft_start_loop(t_struct *s_map)
{
	ft_find_player(s_map);
	mlx_on_event(s_map->m, s_map->w, MLX_WINDOW_EVENT, win_hook, s_map);
	mlx_on_event(s_map->m, s_map->w, MLX_KEYUP, key_hook, s_map);
	mlx_loop(s_map->m);
}
