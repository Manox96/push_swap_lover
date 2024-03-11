/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:57:57 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 19:58:25 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line_bonus/get_next_line.h"
# include <stdlib.h>

struct	s_var_mlx
{
	void		*player;
	void		*player_left;
	void		*player_right;
	void		*player_top;
	void		*col_bottom;
	void		*col_left;
	void		*col_midd;
	void		*col_midd_left;
	void		*col_right;
	void		*col_top;
	void		*c;
	void		*exite;
	void		*wall;
	void		*floor;
	void		*enemy;
	void		*win;
	void		*img;
	void		*mlx;
	int			x;
	int			y;
	int			x_img;
	int			y_img;
};

typedef struct s_tool
{
	struct s_var_mlx	var_mlx;
	char				**map;
	char				*line;
	int					line_number;
	int					size_line;
	int					len;
	int					x;
	int					moves;
	int					y;
	int					fd;
	int					p;
	int					c;
	int					enemy;
	int					e;
	int					i;
	int					j;
	int					timing;
	int					timing_food;
	int					direction;
}	t_tool;

char	**copy_original(char **oroginal, int height, int width);
char	*ft_itoa(int n);
int		strlen_nl(char *str);
int		check_extention(char *str);
int		check_c(char **str);
int		coun_line(int fd);
int		chech_collectble(char **str);
void	left_right(char **str, int line_number, int size_line);
void	printerror(void);
void	check_p_c_e(t_tool p, char **str);
void	check_ones(char **str, int line_number, int size_line);
void	find_cor(char **map, int *x, int *y);
void	check_only_v_0_1_(char **str);
void	initialize_var(t_tool *var);
void	main_game(t_tool *var);
void	to_top(t_tool *var);
void	to_bottom(t_tool *var);
void	to_left(t_tool *var);
void	to_right(t_tool *var);
void	get_pos_player(t_tool *var);
void	swap_to_top(t_tool *var);
void	swap_to_right(t_tool *var);
void	swap_to_left(t_tool *var);
void	swap_to_bottom(t_tool *var);
void	ft_putnbr_fd(int n, int fd);
void	flood_fill_bns(char **cpy, int x, int y);
int		close_win(t_tool *var);
void	set_background(t_tool *var);
void	collectable(t_tool *var, int x, int y);
int		check_c(char **str);
void	which_img(t_tool *var, int i, int j);
void	put_the_images(t_tool *var);
void	chek_wall(t_tool *var);
void	clear_2d(char **str);
void	printmoves(t_tool *var);
void	moves_enemy(t_tool *var);
void	destory_imgs(t_tool *var);
void	check_last_line(int i, char *line, t_tool *var, char **array2d);
void	direction(t_tool *var, int y, int x);
void	enemy_to_left(t_tool *var, int y, int x);
void	enemy_to_right(t_tool *var, int y, int x);
void	check_size(t_tool *var);
void	find_cor_enemy(t_tool *vr, int *x, int *y);
void	check_stranger(char **str);
void	initial_img_direction(t_tool *var);
void	top_tour(t_tool *var, int x, int y);
void	bottom_tour(t_tool *var, int x, int y);
void	left_tour(t_tool *var, int x, int y);
void	right_tour(t_tool *var, int x, int y);
void	initial_collec(t_tool *var);
void	animation_col(t_tool *var);
void	tour(t_tool *var, int x, int y);
void	check_if_fail(t_tool *var);
void	destory_animation(t_tool *var);
void	get_exit_pos(t_tool *var, int *x, int *y);
void	flood_fill_bns_e(char **cpy, int x, int y);

#endif