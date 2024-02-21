/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:00:37 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/21 01:17:21 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_up(t_struct *s)
{
	int	i;

	i = (s->p_y * 32);
	if (s->map[s->p_x - 1][s->p_y] == '1')
		return ;
	else
	{
		if (s->map[s->p_x - 1][s->p_y] == 'E')
		{
			ft_moove_up_exit(s);
			return ;
		}
		s->map[s->p_x][s->p_y] = '0';
		s->map[s->p_x - 1][s->p_y] = 'P';
		mlx_put_image_to_window(s->m, s->w, s->p, i, ((s->p_x - 1) * 32));
		mlx_put_image_to_window(s->m, s->w, s->g, i, (s->p_x * 32));
		s->p_x -= 1;
	}
}

void	ft_moove_down(t_struct *s)
{
	int	i;

	i = (s->p_y * 32);
	if (s->map[s->p_x + 1][s->p_y] == '1')
		return ;
	else
	{
		if (s->map[s->p_x + 1][s->p_y] == 'E')
		{
			ft_moove_down_exit(s);
			return ;
		}
		s->map[s->p_x][s->p_y] = '0';
		s->map[s->p_x + 1][s->p_y] = 'P';
		mlx_put_image_to_window(s->m, s->w, s->p, i, ((s->p_x + 1) * 32));
		mlx_put_image_to_window(s->m, s->w, s->g, i, (s->p_x * 32));
		s->p_x += 1;
	}
}

void	ft_moove_left(t_struct *s)
{
	int	i;

	i = (s->p_x * 32);
	if (s->map[s->p_x][s->p_y - 1] == '1')
		return ;
	else
	{
		if (s->map[s->p_x][s->p_y - 1] == 'E')
		{
			ft_moove_left_exit(s);
			return ;
		}
		s->map[s->p_x][s->p_y] = '0';
		s->map[s->p_x][s->p_y - 1] = 'P';
		mlx_put_image_to_window(s->m, s->w, s->p, ((s->p_y - 1) * 32), i);
		mlx_put_image_to_window(s->m, s->w, s->g, (s->p_y * 32), i);
		s->p_y -= 1;
	}
}

void	ft_moove_right(t_struct *s)
{
	int	i;

	i = (s->p_x * 32);
	if (s->map[s->p_x][s->p_y + 1] == '1')
		return ;
	else
	{
		if (s->map[s->p_x][s->p_y + 1] == 'E')
		{
			ft_moove_right_exit(s);
			return ;
		}
		s->map[s->p_x][s->p_y] = '0';
		s->map[s->p_x][s->p_y + 1] = 'P';
		mlx_put_image_to_window(s->m, s->w, s->p, ((s->p_y + 1) * 32), i);
		mlx_put_image_to_window(s->m, s->w, s->g, (s->p_y * 32), i);
		s->p_y += 1;
	}
}
