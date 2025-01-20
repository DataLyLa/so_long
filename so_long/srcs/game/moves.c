#include "so_long.h"


static int move_up(int keycode, t_game *game, int *found)
{
    int x; 
    int y;

    y = game->player->y;
    x = game->player->x;
    if((keycode == W_KEY || keycode == UP_KEY) 
        && game->map[y - 1][x] != '1')
    {
        if (game->map[y - 1][x] == '2')
        {
            game->alter = game->img->player_tk;
        }
        else if (game->map[y - 1][x] == 'E')
        {
            game->alter = game->img->exit_p;
        }
        else if(game->map[y - 1][x] == 'C')
        {
            game->alter = game->img->player_tk;
            game->map[y - 1][x] = '2';
                *found = 1;
        }
        
        else
            game->alter = game->img->player_t;
        return (game->player->y = y - 1, 1);
    }
    return (0);
}

static int move_down(int keycode, t_game *game, int *found)
{
    int x; 
    int y;

    y = game->player->y;
    x = game->player->x;
    if((keycode == S_KEY || keycode == DOWN_KEY)
        && game->map[y + 1][x] != '1')
    {
        if (game->map[y + 1][x] == '2')
        {
            game->alter = game->img->player_bk;
        }
        else if (game->map[y + 1][x] == 'E')
        {
            game->alter = game->img->exit_p;
        }
        else if(game->map[y + 1][x] == 'C')
        {
            game->alter = game->img->player_bk;
            game->map[y + 1][x] = '2';
                *found = 1;
        }
        else
            game->alter = game->img->player_b;
        return (game->player->y = y + 1, 1);
    }
    return (0);
}

static int move_left(int keycode, t_game *game, int *found)
{
    int x; 
    int y;

    y = game->player->y;
    x = game->player->x;
    if((keycode == A_KEY || keycode == LEFT_KEY) 
        && game->map[y][x - 1] != '1')
    {
        if (game->map[y][x - 1] == '2')
        {
            game->alter = game->img->player_lk;
        }
        else if (game->map[y][x - 1] == 'E')
        {
            game->alter = game->img->exit_p;
        }
        else if(game->map[y][x - 1] == 'C')
        {
            game->alter = game->img->player_lk;
            game->map[y][x - 1] = '2';
                *found = 1;
        }
        else
            game->alter = game->img->player_l;
        return (game->player->x = x - 1, 1);
    }
    return (0);
}

static int move_right(int keycode, t_game *game, int *found)
{
    int x; 
    int y;

    y = game->player->y;
    x = game->player->x;
    if((keycode == D_KEY || keycode == RIGHT_KEY) 
        && game->map[y][x + 1] != '1')
    {
        if (game->map[y][x + 1] == '2')
        {
            game->alter = game->img->player_rk;
        }
        else if (game->map[y][x + 1] == 'E')
        {
            game->alter = game->img->exit_p;
        }
        else if(game->map[y][x + 1] == 'C')
        {
            game->alter = game->img->player_rk;
            game->map[y][x + 1] = '2';
                *found = 1;
        }
        else
            game->alter = game->img->player_r;
        return (game->player->x = x + 1, 1);
    }
    return (0);
}

int	is_move_possible(int keycode, t_game *game, int *found)
{
	*found = 0;
    printf("\npossible\n");
	if (move_up(keycode, game, found))
		return (1);
	if (move_down(keycode, game, found))
		return (1);
	if (move_left(keycode, game, found))
		return (1);
	if (move_right(keycode, game, found))
		return (1);
	return (0);
}

int	move_player(int keycode, t_game *game)
{
	t_coord	old;
	int			found;

	old = *game->player;

    printf("\nmove_player\n");
	if (is_move_possible(keycode, game, &found) == 1)
	{
        if(game->map[old.y][old.x] == '2')
		    mlx_put_image_to_window(game->mlx, game->window, game->back->floor_k,
			old.x * WIDTH, old.y * HEIGHT);
        else if (game->map[old.y][old.x] == 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->img->exit,
			old.x * WIDTH, old.y * HEIGHT);
        else
		    mlx_put_image_to_window(game->mlx, game->window, game->back->floor,
			old.x * WIDTH, old.y * HEIGHT);
        mlx_put_image_to_window(game->mlx, game->window, game->alter,
        game->player->x * WIDTH, game->player->y * HEIGHT);
		if (found)
			game->items++;
		return (1);
	}
	return (0);
}
