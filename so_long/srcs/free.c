#include "so_long.h"

void ft_free_array(char **s)
{
    int i;

    if (s) {
        i = -1;
        while (s[++i]) {
            if (s[i]) {
                free(s[i]);
                s[i] = NULL;
            }
        }
        free(s);
        s = NULL;
    }
}

void ft_free_back(t_game *game)
{
    if (game && game->back)
    {
        if (game->back->floor)
            mlx_destroy_image(game->mlx, game->back->floor);
        if (game->back->floor_k)
            mlx_destroy_image(game->mlx, game->back->floor_k);
        if (game->back->bord_tl)
            mlx_destroy_image(game->mlx, game->back->bord_tl);
        if (game->back->bord_tr)
            mlx_destroy_image(game->mlx, game->back->bord_tr);
        if (game->back->bord_bl)
            mlx_destroy_image(game->mlx, game->back->bord_bl);
        if (game->back->bord_br)
            mlx_destroy_image(game->mlx, game->back->bord_br);
        if (game->back->bord_t)
            mlx_destroy_image(game->mlx, game->back->bord_t);
        if (game->back->bord_l)
            mlx_destroy_image(game->mlx, game->back->bord_l);
        if (game->back->bord_r)
            mlx_destroy_image(game->mlx, game->back->bord_r);
        if (game->back->bord_b)
            mlx_destroy_image(game->mlx, game->back->bord_b);
        if (game->back->wall)
            mlx_destroy_image(game->mlx, game->back->wall);
        free(game->back);
    }

}

void ft_free_img(t_game *game)
{
    if (game && game->img)
    {
        if (game->img->item)
            mlx_destroy_image(game->mlx, game->img->item);
        if (game->img->player_r)
            mlx_destroy_image(game->mlx, game->img->player_r);
        if (game->img->player_rk)
            mlx_destroy_image(game->mlx, game->img->player_rk);
        if (game->img->player_l)
            mlx_destroy_image(game->mlx, game->img->player_l);
        if (game->img->player_lk)
            mlx_destroy_image(game->mlx, game->img->player_lk);
        if (game->img->player_t)
            mlx_destroy_image(game->mlx, game->img->player_t);
        if (game->img->player_tk)
            mlx_destroy_image(game->mlx, game->img->player_tk);
        if (game->img->player_b)
            mlx_destroy_image(game->mlx, game->img->player_b);
        if (game->img->player_bk)
            mlx_destroy_image(game->mlx, game->img->player_bk);
        if (game->img->exit)
            mlx_destroy_image(game->mlx, game->img->exit);
        if (game->img->exit_p)
            mlx_destroy_image(game->mlx, game->img->exit_p);
        if (game->img->exit_k)
            mlx_destroy_image(game->mlx, game->img->exit_k);
        free(game->img);
    }
}

void ft_free_game(t_game *game, int i)
{
    if (game)
    {
        if(game->window)
            mlx_destroy_window(game->mlx, game->window);
        if (game->player)
            free(game->player);
        if (game->start)
            free(game->start);
        if (game->end)
            free(game->end);
        if (game->back)
            ft_free_back(game);
        if (game->img)
            ft_free_img(game);
        if(game->mlx)
	        mlx_destroy_display(game->mlx);
        if (game->map)
            ft_free_array(game->map);
        free(game->mlx);
        exit(i);
    }
}
