#include "so_long.h"

void imgs_back_init(t_game *game)
{
	game->back = (t_back *)malloc(sizeof(t_back));
	if(!game->back)
	{
		error_void("Game images memory init failed");
		ft_free_game(game, EXIT_FAILURE);
	}
	game->back->floor = NULL;
	game->back->floor_k = NULL;
	game->back->bord_tl = NULL;
	game->back->bord_tr = NULL;
	game->back->bord_br = NULL;
	game->back->bord_bl = NULL;
	game->back->bord_t = NULL;
	game->back->bord_b = NULL;
	game->back->bord_l = NULL;
	game->back->bord_r = NULL;
	game->back->wall = NULL;
}

void imgs_img_init(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	if(!game->img)
	{
		error_void("Game images memory init failed");
		ft_free_game(game, EXIT_FAILURE);
	}
	game->img->item = NULL;
	game->img->player_b = NULL;
	game->img->player_bk = NULL;
	game->img->player_l = NULL;
	game->img->player_lk = NULL;
	game->img->player_r = NULL;
	game->img->player_rk = NULL;
	game->img->player_t = NULL;
	game->img->player_tk = NULL;
	game->img->exit = NULL;
	game->img->exit_p = NULL;
	game->img->exit_k = NULL;
}

void game_back_init(t_game *game)
{
	t_coord c;

	c.x = 50;
	c.y = 50;
	game->back->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &c.y, &c.x);
	ft_printf("\nfloor : %d\n", game->back->floor);
	game->back->floor_k = mlx_xpm_file_to_image(game->mlx, FLOOR_K, &c.y, &c.x);
	ft_printf("\nfloor_k : %d\n", game->back->floor_k);
	game->back->bord_tl = mlx_xpm_file_to_image(game->mlx, BORD_TL, &c.y, &c.x);
	ft_printf("\nbord_tl : %d\n", game->back->bord_tl);
	game->back->bord_tr = mlx_xpm_file_to_image(game->mlx, BORD_TR, &c.y, &c.x);
	ft_printf("\nbord_tr : %d\n", game->back->bord_tr);
	game->back->bord_bl = mlx_xpm_file_to_image(game->mlx, BORD_BL, &c.y, &c.x);
	ft_printf("\nbord_bl : %d\n", game->back->bord_bl);
	game->back->bord_br = mlx_xpm_file_to_image(game->mlx, BORD_BR, &c.y, &c.x);
	ft_printf("\nbord_br : %d\n", game->back->bord_br);
	game->back->bord_t = mlx_xpm_file_to_image(game->mlx, BORD_T, &c.y, &c.x);
	ft_printf("\nbord_t : %d\n", game->back->bord_t);
	game->back->bord_l = mlx_xpm_file_to_image(game->mlx, BORD_L, &c.y, &c.x);
	ft_printf("\nbord_l : %d\n", game->back->bord_l);
	game->back->bord_r = mlx_xpm_file_to_image(game->mlx, BORD_R, &c.y, &c.x);
	ft_printf("\nbord_r : %d\n", game->back->bord_r);
	game->back->bord_b = mlx_xpm_file_to_image(game->mlx, BORD_B, &c.y, &c.x);
	ft_printf("\nbord_b : %d\n", game->back->bord_b);
	game->back->wall = mlx_xpm_file_to_image(game->mlx, WALL, &c.y, &c.x);
	ft_printf("\nwall : %d\n", game->back->wall);
	if(!game->back->floor || !game->back->floor_k || !game->back->bord_tl || !game->back->bord_tr 
		|| !game->back->bord_bl || !game->back->bord_br || !game->back->bord_t || !game->back->bord_l 
		|| !game->back->bord_r || !game->back->bord_b || !game->back->wall)
	{
		error_void("Game background init failed");
		ft_free_game(game, EXIT_FAILURE);
	}
}

void game_img_init(t_game *game)
{
	t_coord c;

	c.x = 50;
	c.y = 50;
	game->img->item = mlx_xpm_file_to_image(game->mlx, EGG, &c.y, &c.x);
	ft_printf("\nitem : %d\n", game->img->item);
	game->img->player_r = mlx_xpm_file_to_image(game->mlx, PLAYER_R, &c.y, &c.x);
	ft_printf("\nplayer_r : %d\n", game->img->player_r);
	game->img->player_rk = mlx_xpm_file_to_image(game->mlx, PLAYER_RK, &c.y, &c.x);
	ft_printf("\nplayer_rk : %d\n", game->img->player_rk);
	game->img->player_l = mlx_xpm_file_to_image(game->mlx, PLAYER_L, &c.y, &c.x);
	ft_printf("\nplayer_l : %d\n", game->img->player_l);
	game->img->player_lk = mlx_xpm_file_to_image(game->mlx, PLAYER_LK, &c.y, &c.x);
	ft_printf("\nplayer_lk : %d\n", game->img->player_lk);
	game->img->player_t = mlx_xpm_file_to_image(game->mlx, PLAYER_T, &c.y, &c.x);
	ft_printf("\nplayer_t : %d\n", game->img->player_t);
	game->img->player_tk = mlx_xpm_file_to_image(game->mlx, PLAYER_TK, &c.y, &c.x);
	ft_printf("\nplayer_tk : %d\n", game->img->player_tk);
	game->img->player_b = mlx_xpm_file_to_image(game->mlx, PLAYER_B, &c.y, &c.x);
	ft_printf("\nplayer_b : %d\n", game->img->player_b);
	game->img->player_bk = mlx_xpm_file_to_image(game->mlx, PLAYER_BK, &c.y, &c.x);
	ft_printf("\nplayer_bk : %d\n", game->img->player_bk);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &c.y, &c.x);
	ft_printf("\nexit : %d\n", game->img->exit);
	game->img->exit_p = mlx_xpm_file_to_image(game->mlx, EXIT_P, &c.y, &c.x);
	ft_printf("\nexit : %d\n", game->img->exit_p);
	game->img->exit_k = mlx_xpm_file_to_image(game->mlx, EXIT_K, &c.y, &c.x);
	ft_printf("\nexit_k : %d\n", game->img->exit_k);
	if( !game->img->item || !game->img->player_r || !game->img->player_rk || !game->img->player_l 
		|| !game->img->player_lk|| !game->img->player_t || !game->img->player_tk || !game->img->player_b 
		|| !game->img->player_bk || !game->img->exit || !game->img->exit_p || !game->img->exit_k)
	{
		error_void("Game images init failed");
		ft_free_game(game, EXIT_FAILURE);
	}
}

void game_init(t_game *game, char **map, t_check *ck)
{
    game->map = map;
	game->player = find_position(map, 'P');
	game->start = find_position(map, 'P');
	game->end = find_position(map, 'E');
    game->size.x = ft_strlen(map[0]);
    game->size.y = ft_arrlen(map);
    if(!game->player || !game->start || !game->end || !game->size.x || !game->size.y)
	{
		error_void("Game struct init - !player | !P | !E |!size");
		ft_free_game(game, EXIT_FAILURE);
	}
	game->total = *ck;
	game->items = 0;
	game->moves = 0;
	game->mlx = mlx_init();
    if (!game->mlx)
	{
		error_void("Launch MLX failed");
		ft_free_game(game, EXIT_FAILURE);
	}
	game->window = NULL;
	imgs_back_init(game);
	imgs_img_init(game);
	game_back_init(game);
	game_img_init(game);
	game->alter = game->img->player_b;
}
