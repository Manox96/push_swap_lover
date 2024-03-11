/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:57:57 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 17:07:20 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <mlx.h>

struct	s_var_mlx
{
	void		*player;
	void		*c;
	void		*exite;
	void		*wall;
	void		*floor;
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
	int					e;
	int					i;
	int					j;
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
void	check_p_c_e(char **str);
void	check_ones(char **str, int line_number, int size_line);
void	find_cor(char **map, int *x, int *y);
void	check_only_v_0_1_(char **str);
void	initialize_var(t_tool *var);
void	main_game(t_tool *var);
void	get_pos_player(t_tool *var);
void	swap_to_top(t_tool *var);
void	swap_to_right(t_tool *var);
void	swap_to_left(t_tool *var);
void	swap_to_bottom(t_tool *var);
void	ft_putnbr_fd(int n, int fd);
void	flood_fill(char **cpy, int x, int y);
int		close_win(t_tool *var);
void	set_background(t_tool *var);
void	collectable(t_tool *var, int x, int y);
int		check_c(char **str);
void	which_img(t_tool *var, int i, int j);
void	put_the_images(t_tool *var);
void	chek_wall(t_tool *var);
void	clear_2d(char **str);
void	destory_imgs(t_tool *var);
void	check_last_line(int i, char *line, t_tool *var, char **array2d);
void	check_size(t_tool *var);
void	get_exit_pos(char **str, int *x, int *y);
void	flood_fill_e(char **cpy, int x, int y);

#endif