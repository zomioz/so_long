/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:01 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/21 01:49:54 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_up_exit(t_struct *s)
{
	int	i;
	int	j;

	i = (s->p_y * 32);
	j = (s->p_x * 32);
	if (ft_check_collectible(s) == 0)
	{
		mlx_loop_end(s->m);
		return ;
	}
	s->map[s->p_x][s->p_y] = 'E';
	s->map[s->p_x - 1][s->p_y] = 'P';
	mlx_put_image_to_window(s->m, s->w, s->p, i, ((s->p_x - 1) * 32));
	mlx_put_image_to_window(s->m, s->w, s->e, i, j);
	s->p_x -= 1;
	return ;
}

void	ft_moove_down_exit(t_struct *s)
{
	int	i;
	int	j;

	i = (s->p_y * 32);
	j = (s->p_x * 32);
	if (ft_check_collectible(s) == 0)
	{
		mlx_loop_end(s->m);
		return ;
	}
	s->map[s->p_x][s->p_y] = 'E';
	s->map[s->p_x + 1][s->p_y] = 'P';
	mlx_put_image_to_window(s->m, s->w, s->p, i, ((s->p_x + 1) * 32));
	mlx_put_image_to_window(s->m, s->w, s->e, i, j);
	s->p_x += 1;
	return ;
}

void	ft_moove_left_exit(t_struct *s)
{
	int	i;
	int	j;

	i = (s->p_y * 32);
	j = (s->p_x * 32);
	if (ft_check_collectible(s) == 0)
	{
		mlx_loop_end(s->m);
		return ;
	}
	s->map[s->p_x][s->p_y - 1] = 'P';
	s->map[s->p_x][s->p_y] = 'E';
	mlx_put_image_to_window(s->m, s->w, s->p, ((s->p_y - 1) * 32), j);
	mlx_put_image_to_window(s->m, s->w, s->e, i, j);
	s->p_y -= 1;
	return ;
}

void	ft_moove_right_exit(t_struct *s)
{
	int	i;
	int	j;

	i = (s->p_y * 32);
	j = (s->p_x * 32);
	if (ft_check_collectible(s) == 0)
	{
		mlx_loop_end(s->m);
		return ;
	}
	s->map[s->p_x][s->p_y] = 'E';
	s->map[s->p_x][s->p_y + 1] = 'P';
	mlx_put_image_to_window(s->m, s->w, s->p, ((s->p_y + 1) * 32), j);
	mlx_put_image_to_window(s->m, s->w, s->e, i, j);
	s->p_y += 1;
	return ;
}
