/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:01:26 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/29 22:59:57 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define TILE_SZ 128
# define TILE_GROUND 0
# define TILE_WALL 4
# define TILE_EXIT_CLOSED 8
# define TILE_EXIT_OPENED 9
# define TILE_COIN 16
# define TILE_PLAYER 20
# define TILE_YOUWIN 36
# define TILE_YOULOOSE 37
# define TILE_GHOST 38
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define GH_MOVELEFT 'G'
# define GH_MOVERIGHT 'K'
# define PL_MOVESTOP 0
# define PL_MOVE 1
# define PL_DIRDOWN 0
# define PL_DIRLEFT 3
# define PL_DIRUP 6
# define PL_DIRRIGHT 9

typedef struct s_gmap
{
	int		col;
	int		row;
	int		coins;
	int		exits;
	int		patrol;
	int		collected;
	int		pl_col;
	int		pl_row;
	int		pl_move;
	int		pl_mv2col;
	int		pl_mv2row;
	int		pl_direction;
	int		movements;
	char	*mov_str;
	char	**map;
}	t_gmap;

typedef struct s_gwin
{
	void	*mlx;
	void	*mlx_win;
	void	*tile[42];
	int		x_wind;
	int		y_wind;
	int		frame;
	int		render;
	t_gmap	gmap;
}	t_gwin;

void	init_map(t_gmap *gmap);
void	init_gwin(t_gwin *gwin);
void	clean_map(t_gmap *gmap);
int		getfd_mapfile(char *mpath);
int		load_map(t_gmap *gmap, char *mpath);
int		loadtile(t_gwin *gwin);
void	clean_gwin(t_gwin *gwin);
int		closewin_h(t_gwin *gwin);
int		keydown_h(int keycode, t_gwin *gwin);
int		render_h(t_gwin *gwin);
int		update_window(t_gwin *gwin);
int		draw_tile(t_gwin *gwin, char tile, int x, int y);
void	draw_ground(t_gwin *gwin, int x, int y);
void	draw_wall(t_gwin *gwin, int x, int y);
void	draw_coin(t_gwin *gwin, int x, int y);
void	draw_patrol(t_gwin *gwin, int x, int y);
int		mv_patrol_right(t_gwin *gwin, int x, int y);
int		mv_patrol_left(t_gwin *gwin, int x, int y);
void	draw_player(t_gwin *gwin);
void	draw_exit(t_gwin *gwin, int x, int y);
void	draw_youwin(t_gwin *gwin);
void	draw_youloose(t_gwin *gwin);
int		pl_move_up(t_gwin *gwin);
int		pl_move_down(t_gwin *gwin);
int		pl_move_left(t_gwin *gwin);
int		pl_move_right(t_gwin *gwin);
int		level_complete(t_gwin *gwin);
int		level_fail(t_gwin *gwin);
void	count_movements(t_gwin *gwin);
void	draw_movements(t_gwin *gwin);
#endif
