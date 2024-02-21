/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:49:26 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/17 18:10:18 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../MacroLibX/includes/mlx.h"

typedef struct s_struct
{
	char	**map;
	void	*m;
	void	*w;
	int		p_x;
	int		p_y;
	int		s;
	void	*w_s;
	void	*w_et;
	void	*w_eb;
	void	*w_el;
	void	*w_er;
	void	*w_lr;
	void	*w_tb;
	void	*w_bl;
	void	*w_br;
	void	*w_tl;
	void	*w_tr;
	void	*w_ltr;
	void	*w_trb;
	void	*w_rbl;
	void	*w_blt;
	void	*w_f;
	void	*g;
	void	*c;
	void	*e;
	void	*p;
	int		x;
	int		y;
}t_struct;

int		ft_check_file(char *argv);
int		ft_check_inside(char *str);
int		ft_checker_outside_tb(t_struct *s_map);
int		ft_checker_outside_lr(t_struct *s_map);
int		ft_checker_length(t_struct *s_map);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_free_struct(t_struct *s_map);
int		ft_start_map(char *stock);
int		ft_create_tab(char *argv);
int		ft_start_file(t_struct *s_map);
void	ft_go_map(t_struct *s_map);
int		ft_nb_lines(t_struct *s_map);
void	ft_destruct_wall(t_struct *wall);
void	ft_init_wall(t_struct *w);
int		ft_checker_out(t_struct *s);
void	ft_wall_one(t_struct *s_map);
void	ft_wall_three(t_struct *s);
void	ft_wall_three_bis(t_struct *s, int columns, int lines);
void	ft_wall_two(t_struct *s);
void	ft_checker_wall(t_struct *s_map);
void	ft_destruct_other(t_struct *s_map);
void	ft_init_other(t_struct *s_map);
void	ft_draw_other(t_struct *s_map);
void	ft_draw_image(t_struct *s_map);
void	ft_start_loop(t_struct *s_map);
void	ft_print_other(t_struct *s_map);
void	ft_find_player(t_struct *s_map);
int		ft_check_collectible(t_struct *s_map);
void	ft_moove_up(t_struct *s_map);
void	ft_moove_down(t_struct *s_map);
void	ft_moove_left(t_struct *s_map);
void	ft_moove_right(t_struct *s_map);
void    ft_moove_up_exit(t_struct *s);
void    ft_moove_left_exit(t_struct *s);
void    ft_moove_down_exit(t_struct *s);
void    ft_moove_right_exit(t_struct *s);

#endif
