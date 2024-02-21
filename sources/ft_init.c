/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:21:17 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 23:15:35 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destruct_wall(t_struct *s_map)
{
	mlx_destroy_image(s_map->m, s_map->w_s);
	mlx_destroy_image(s_map->m, s_map->w_et);
	mlx_destroy_image(s_map->m, s_map->w_eb);
	mlx_destroy_image(s_map->m, s_map->w_el);
	mlx_destroy_image(s_map->m, s_map->w_er);
	mlx_destroy_image(s_map->m, s_map->w_lr);
	mlx_destroy_image(s_map->m, s_map->w_tb);
	mlx_destroy_image(s_map->m, s_map->w_bl);
	mlx_destroy_image(s_map->m, s_map->w_br);
	mlx_destroy_image(s_map->m, s_map->w_tl);
	mlx_destroy_image(s_map->m, s_map->w_tr);
	mlx_destroy_image(s_map->m, s_map->w_ltr);
	mlx_destroy_image(s_map->m, s_map->w_trb);
	mlx_destroy_image(s_map->m, s_map->w_rbl);
	mlx_destroy_image(s_map->m, s_map->w_blt);
	mlx_destroy_image(s_map->m, s_map->w_f);
	mlx_destroy_image(s_map->m, s_map->g);
}

void	ft_init_wall(t_struct *w)
{
	w->s = 32;
	w->x = 0;
	w->y = 0;
	w->w_s = mlx_png_file_to_image(w->m, "textures/w_s.png", &w->s, &w->s);
	w->w_et = mlx_png_file_to_image(w->m, "textures/w_et.png", &w->s, &w->s);
	w->w_eb = mlx_png_file_to_image(w->m, "textures/w_eb.png", &w->s, &w->s);
	w->w_el = mlx_png_file_to_image(w->m, "textures/w_el.png", &w->s, &w->s);
	w->w_er = mlx_png_file_to_image(w->m, "textures/w_er.png", &w->s, &w->s);
	w->w_lr = mlx_png_file_to_image(w->m, "textures/w_lr.png", &w->s, &w->s);
	w->w_tb = mlx_png_file_to_image(w->m, "textures/w_tb.png", &w->s, &w->s);
	w->w_bl = mlx_png_file_to_image(w->m, "textures/w_bl.png", &w->s, &w->s);
	w->w_br = mlx_png_file_to_image(w->m, "textures/w_br.png", &w->s, &w->s);
	w->w_tl = mlx_png_file_to_image(w->m, "textures/w_tl.png", &w->s, &w->s);
	w->w_tr = mlx_png_file_to_image(w->m, "textures/w_tr.png", &w->s, &w->s);
	w->w_ltr = mlx_png_file_to_image(w->m, "textures/w_ltr.png", &w->s, &w->s);
	w->w_trb = mlx_png_file_to_image(w->m, "textures/w_trb.png", &w->s, &w->s);
	w->w_rbl = mlx_png_file_to_image(w->m, "textures/w_rbl.png", &w->s, &w->s);
	w->w_blt = mlx_png_file_to_image(w->m, "textures/w_blt.png", &w->s, &w->s);
	w->w_f = mlx_png_file_to_image(w->m, "textures/w_f.png", &w->s, &w->s);
	w->g = mlx_png_file_to_image(w->m, "textures/ground.png", &w->s, &w->s);
}

void	ft_destruct_other(t_struct *s_map)
{
	mlx_destroy_image(s_map->m, s_map->c);
	mlx_destroy_image(s_map->m, s_map->p);
	mlx_destroy_image(s_map->m, s_map->e);
}

void	ft_init_other(t_struct *s)
{
	s->c = mlx_png_file_to_image(s->m, "textures/coin.png", &s->s, &s->s);
	s->p = mlx_png_file_to_image(s->m, "textures/player.png", &s->s, &s->s);
	s->e = mlx_png_file_to_image(s->m, "textures/exit.png", &s->s, &s->s);
}
