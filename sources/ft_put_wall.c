/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:49:14 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 23:09:34 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checker_out(t_struct *s)
{
	int	check;
	int	lines;
	int	columns;

	columns = ft_strlen(s->map[0]);
	lines = ft_nb_lines(s);
	check = 0;
	if (s->x < (lines - 1) && s->map[s->x + 1][s->y] == '1')
		check = check + 1;
	if (s->x > 0 && s->map[s->x - 1][s->y] == '1')
		check = check + 1;
	if (s->y < (columns - 1) && s->map[s->x][s->y + 1] == '1')
		check = check + 1;
	if (s->y > 0 && s->map[s->x][s->y - 1] == '1')
		check = check + 1;
	return (check);
}

void	ft_wall_one(t_struct *s)
{
	int	i;
	int	j;

	i = (s->y * 32);
	j = (s->x * 32);
	if (s->map[s->x + 1] && s->map[s->x + 1][s->y] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_et, i, j);
	if (s->map[s->x - 1] && s->map[s->x - 1][s->y] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_eb, i, j);
	if (s->map[s->x][s->y + 1] && s->map[s->x][s->y + 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_el, i, j);
	if (s->map[s->x][s->y - 1] && s->map[s->x][s->y - 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_er, i, j);
}

void	ft_wall_two(t_struct *s)
{
	int	lines;
	int	columns;

	columns = ft_strlen(s->map[0]);
	lines = ft_nb_lines(s);
	if (s->x > 0 && s->x < (lines - 1) && s->map[s->x - 1][s->y] == '1'
		&& s->map[s->x + 1][s->y] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_tb, (s->y * 32), (s->x * 32));
	else if (s->y > 0 && s->y < (columns - 1) && s->map[s->x][s->y + 1] == '1'
		&& s->map[s->x][s->y - 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_lr, (s->y * 32), (s->x * 32));
	else if (s->x < (lines - 1) && s->y < (columns - 1)
		&& s->map[s->x + 1][s->y] == '1' && s->map[s->x][s->y + 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_br, (s->y * 32), (s->x * 32));
	else if (s->x < (lines - 1) && s->y > 0 && s->map[s->x + 1][s->y] == '1'
		&& s->map[s->x][s->y - 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_bl, (s->y * 32), (s->x * 32));
	else if (s-> x > 0 && s->y > 0 && s->map[s->x - 1][s->y] == '1'
		&& s->map[s->x][s->y - 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_tl, (s->y * 32), (s->x * 32));
	else if (s-> x > 0 && s->y < (columns - 1) && s->map[s->x - 1][s->y] == '1'
		&& s->map[s->x][s->y + 1] == '1')
		mlx_put_image_to_window(s->m, s->w, s->w_tr, (s->y * 32), (s->x * 32));
}

void	ft_wall_three_bis(t_struct *s, int columns, int lines)
{
	int	i;
	int	j;

	i = (s->y * 32);
	j = (s->x * 32);
	if (s->y < (columns - 1) && s->x > 0 && s->x < (lines - 1))
	{
		if (s->y == 0 || s->map[s->x][s->y - 1] != '1')
			mlx_put_image_to_window(s->m, s->w, s->w_trb, i, j);
	}
	if (s->y > 0 && s->x > 0 && s->x < (lines - 1))
	{
		if (s->y == (columns - 1) || s->map[s->x][s->y + 1] != '1')
			mlx_put_image_to_window(s->m, s->w, s->w_blt, i, j);
	}
}

void	ft_wall_three(t_struct *s)
{
	int	lines;
	int	columns;
	int	i;
	int	j;

	i = (s->y * 32);
	j = (s->x * 32);
	columns = ft_strlen(s->map[0]);
	lines = ft_nb_lines(s);
	if (s->x < (lines - 1) && s->y > 0 && s->y < (columns - 1))
	{
		if (s->x == 0 || s->map[s->x - 1][s->y] != '1')
			mlx_put_image_to_window(s->m, s->w, s->w_rbl, i, j);
	}
	if (s->x > 0 && s->y > 0 && s->y < (columns - 1))
	{
		if (s->x == (lines - 1) || s->map[s->x + 1][s->y] != '1')
			mlx_put_image_to_window(s->m, s->w, s->w_ltr, i, j);
	}
	ft_wall_three_bis(s, columns, lines);
}
