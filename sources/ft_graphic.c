/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:41:37 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 23:14:53 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_other(t_struct *s)
{
	int	i;
	int	j;

	s->x = 0;
	s->y = 0;
	while (s->map[s->x])
	{
		while (s->map[s->x][s->y])
		{
			i = (s->y * 32);
			j = (s->x * 32);
			if (s->map[s->x][s->y] == 'P')
				mlx_put_image_to_window(s->m, s->w, s->p, i, j);
			else if (s->map[s->x][s->y] == 'C')
				mlx_put_image_to_window(s->m, s->w, s->c, i, j);
			else if (s->map[s->x][s->y] == 'E')
				mlx_put_image_to_window(s->m, s->w, s->e, i, j);
			s->y++;
		}
		s->y = 0;
		s->x++;
	}
}

void	ft_checker_wall(t_struct *s)
{
	int	check;

	check = ft_checker_out(s);
	if (check == 0)
		mlx_put_image_to_window(s->m, s->w, s->w_s, (s->y * 32), (s->x * 32));
	else if (check == 4)
		mlx_put_image_to_window(s->m, s->w, s->w_f, (s->y * 32), (s->x * 32));
	else if (check == 1)
		ft_wall_one(s);
	else if (check == 2)
		ft_wall_two(s);
	else if (check == 3)
		ft_wall_three(s);
	else
		mlx_put_image_to_window(s->m, s->w, s->w_s, (s->y * 32), (s->x * 32));
}

void	ft_put_image(t_struct *s)
{
	int		lines;
	int		i;
	int		j;

	lines = ft_nb_lines(s);
	while (s->x < lines)
	{
		while (s->map[s->x][s->y])
		{
			i = (s->y * 32);
			j = (s->x * 32);
			if (s->map[s->x][s->y] == '1')
				ft_checker_wall(s);
			else if (s->map[s->x][s->y] == '0')
				mlx_put_image_to_window(s->m, s->w, s->g, i, j);
			s->y++;
		}
		s->y = 0;
		s->x++;
	}
	ft_print_other(s);
}

void	ft_go_map(t_struct *s)
{
	int		lines;
	int		columns;

	lines = ft_nb_lines(s);
	columns = ft_strlen(s->map[0]);
	s->m = mlx_init();
	s->w = mlx_new_window(s->m, (columns * 32), (lines * 32), "so_long");
	ft_init_wall(s);
	ft_init_other(s);
	ft_put_image(s);
	ft_start_loop(s);
	ft_destruct_other(s);
	ft_destruct_wall(s);
	mlx_destroy_window(s->m, s->w);
	mlx_destroy_display(s->m);
	ft_free_struct(s);
}
