#include "so_long.h"

void print_top(t_game *game)
{
    t_coord  c;

    c.x = -1;
    c.y = 0;
    while(game->map[c.y][++c.x] && c.x < game->size.x)
    {
        if(c.x == 0)
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_tl, c.x * WIDTH, c.y * HEIGHT);
        else if(c.x == (game->size.x - 1))
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_tr, c.x * WIDTH, c.y * HEIGHT);
        else
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_t, c.x * WIDTH, c.y * HEIGHT);
    }
}

void print_bottom(t_game *game)
{
    t_coord  c;

    c.y = game->size.y - 1;
    c.x = -1;
    while(game->map[c.y][++c.x] && c.x < game->size.x)
    {
        if(c.x == 0)
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_bl, c.x * WIDTH, c.y * HEIGHT);
        else if(c.x == (game->size.x - 1))
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_br, c.x * WIDTH, c.y * HEIGHT);
        else
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_b, c.x * WIDTH, c.y * HEIGHT);
    }
}

void print_left_right(t_game *game, char *s)
{
    t_coord  c;

    
    if (ft_strcmp(s, "left") == 0)
    {
        c.x = 0;
        c.y = 0;
        while (game->map[++c.y][c.x] && c.y < (game->size.y - 1))
        {
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_l, c.x * WIDTH, c.y * HEIGHT);
        }
    }
    if(ft_strcmp(s, "right") == 0)
    {
        c.x = game->size.x - 1;
        c.y = 0;
        while(game->map[++c.y][c.x] && c.y < (game->size.y - 1))
        {
            mlx_put_image_to_window(game->mlx, game->window, game->back->bord_r, c.x * WIDTH, c.y * HEIGHT);
        }
    }
}

void print_intern(t_game *game)
{
    t_coord c;

    c.y = 0;
    {
        while (game->map[++c.y] && c.y < game->size.y - 1)
        {
            c.x = 0;
            while (game->map[c.y][++c.x] && c.x < game->size.x - 1)
            {
                if(game->map[c.y][c.x] == '1')
                    mlx_put_image_to_window(game->mlx, game->window, game->back->wall, c.x * WIDTH, c.y * HEIGHT);
                else if(game->map[c.y][c.x] == 'C')
                    mlx_put_image_to_window(game->mlx, game->window, game->img->item, c.x * WIDTH, c.y * HEIGHT);
                else if(game->map[c.y][c.x] == 'P')
                    mlx_put_image_to_window(game->mlx, game->window, game->alter, c.x * WIDTH, c.y * HEIGHT);
                else if(game->map[c.y][c.x] == 'E')
                    mlx_put_image_to_window(game->mlx, game->window, game->img->exit, c.x * WIDTH, c.y * HEIGHT);
                else
                    mlx_put_image_to_window(game->mlx, game->window, game->back->floor, c.x * WIDTH, c.y * HEIGHT);
            }
        }
    }
}

void    print_map(t_game *game)
{
    print_top(game);
    print_bottom(game);
    print_left_right(game, "left");
    print_left_right(game, "right");
    print_intern(game);
}
