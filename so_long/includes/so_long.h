#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

# define WIDTH			50
# define HEIGHT			50

# define BORD_TL		"./imgs/bord_tl.xpm"
# define BORD_TR		"./imgs/bord_tr.xpm"
# define BORD_BL		"./imgs/bord_bl.xpm"
# define BORD_BR		"./imgs/bord_br.xpm"

# define BORD_T		"./imgs/bord_t.xpm"
# define BORD_B		"./imgs/bord_b.xpm"
# define BORD_L		"./imgs/bord_l.xpm"
# define BORD_R		"./imgs/bord_r.xpm"

# define FLOOR		"./imgs/floor.xpm"
# define FLOOR_K		"./imgs/floor_k.xpm"
# define WALL		"./imgs/wall.xpm"

# define EGG		"./imgs/egg.xpm"
# define HOUSE		"./imgs/house.xpm"
# define HOUSE_K	"./imgs/house_k.xpm"
# define EXIT		"./imgs/house.xpm"
# define EXIT_P		"./imgs/house_o.xpm"
# define EXIT_K		"./imgs/house_k.xpm"

# define PLAYER_T		"./imgs/up.xpm"
# define PLAYER_B		"./imgs/down.xpm"
# define PLAYER_L		"./imgs/left.xpm"
# define PLAYER_R		"./imgs/right.xpm"

# define PLAYER_TK		"./imgs/up_k.xpm"
# define PLAYER_BK		"./imgs/down_k.xpm"
# define PLAYER_LK		"./imgs/left_k.xpm"
# define PLAYER_RK		"./imgs/right_k.xpm"

# define CROSS			17
# define ESC_KEY		65307
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100
# define UP_KEY			65362
# define LEFT_KEY		65361
# define DOWN_KEY		65364
# define RIGHT_KEY		65363

typedef struct  s_check
{
	int	c;
	int	p;
	int	e;
	int	n;
}               t_check;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_back
{
	void		*floor;
	void		*floor_k;
	void		*bord_tl;
	void		*bord_tr;
	void		*bord_bl;
	void		*bord_br;
	void		*bord_t;
	void		*bord_l;
	void		*bord_r;
	void		*bord_b;
	void		*wall;
}				t_back;


typedef struct	s_img
{
	void		*item;
	void		*player_r;
	void		*player_rk;
	void		*player_l;
	void		*player_lk;
	void		*player_t;
	void		*player_tk;
	void		*player_b;
	void		*player_bk;
	void		*exit;
	void		*exit_p;
	void		*exit_k;
}				t_img;

typedef struct s_game
{
	char		**map;
	t_coord		*player;
	t_coord		*start;
	t_coord		*end;
	t_coord		size;
	t_check		total;
	int			items;
	int			moves;
	void		*mlx;
	void		*window;
	void 		*alter;
	t_img		*img;
	t_back		*back;
}				t_game;

//Handle map
char	**check_map(char *f_map, t_check *ck);
char *create_map_buff(int fd);
int map_content(char *s_map, t_check *ck);
char **create_map(char *s_map, t_check *ck);
int map_gameboard(char **map);
int board_limits(char ** map);
char **ft_arrcpy(char **s);
int flood_fill(char **map, t_coord pos);
int solvable_game(char **map, t_check *ck);

//utils and new generic fonction
void ft_free_array(char **s);
void ft_free_back(t_game *game);
void ft_free_img(t_game *game);
void ft_free_game(t_game *game, int i);

char **error_arr(char *s);
char *error_str(char *s);
int error_int(char *s);
void error_void(char *s);

int ft_arrlen(char **s);
t_coord *find_position(char **arr, char c);
int	screen_size(t_game *game);

//gaming part
void game_init(t_game *game, char **map, t_check *ck);
void imgs_back_init(t_game *game);
void imgs_img_init(t_game *game);
void game_back_init(t_game *game);
void game_img_init(t_game *game);
int start_game(t_game *game);

void    print_map(t_game *game);
void print_intern(t_game *game);
void print_left_right(t_game *game, char *s);
void print_bottom(t_game *game);
void print_top(t_game *game);

int	press_cross(t_game *game);
int	is_move_possible(int keycode, t_game *game, int *found_coin);
int	move_player(int keycode, t_game *game);


#endif