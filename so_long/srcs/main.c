#include "so_long.h"

int check_end(int key, t_game *game)
{
    if(key == ESC_KEY)
	    return (ft_printf("\nGame closed with ESC_KEY\n"), ft_free_game(game, EXIT_SUCCESS), 0);
    if (key == W_KEY || key == A_KEY || key == S_KEY
		|| key == D_KEY || key == UP_KEY || key == LEFT_KEY
		|| key == DOWN_KEY || key == RIGHT_KEY)
    {
        if(move_player(key, game) == 1)
        {
            if(++game->moves < 2)
                ft_printf("\nYou made %d move\n", game->moves);
            else
                ft_printf("\nYou made %d moves\n", game->moves);
        }
    }
    if(game->items == game->total.c && game->player->y == game->end->y && game->player->x == game->end->x)
    {
        mlx_put_image_to_window(game->mlx, game->window, game->img->exit_k, game->end->x * WIDTH, game->end->y * HEIGHT);
        return (ft_free_game(game, EXIT_SUCCESS), 0);
    } 
    return (1);
}

int	press_cross(t_game *game)
{
	return (ft_printf("\nGame closed with CROSS\n"),ft_free_game(game, EXIT_SUCCESS), 0);
}

int start_game(t_game *game)
{
    printf("\nin start\n");
    game->window = mlx_new_window(game->mlx, (game->size.x * WIDTH), (game->size.y * HEIGHT), "so long");
    if(!game->window)
        (perror("Error\nGame display failed\n"), ft_free_game(game, EXIT_FAILURE));
    print_map(game);
    printf("\nprint_map pass\n");
	mlx_hook(game->window, 2, 1L, check_end, game);
	mlx_hook(game->window, CROSS, 0, press_cross, game);
    mlx_loop(game->mlx);
    return (ft_free_game(game, EXIT_SUCCESS), 0);
}

int main(int ac, char **av)
{
    t_check check = {0};
    char	**map;
    t_game game = {0};

    if (ac != 2)
        return (ft_printf("\nUsage : ./so_long <map_file>\n"), 1);
    map = check_map(av[1], &check);
    if (!map)
    {
        return (1);
    }
	game_init(&game, map, &check);
    if (!screen_size(&game))
    {
        (ft_free_array(map), ft_free_game(&game, EXIT_FAILURE));
    }
    printf("\nMap Done\n");
    printf("\ntotal item : %d, item : %d\n", game.total.c, game.items);
    // if(!start_game(&game))
    //     return(error_void("Start game failed"), ft_free_array(map), ft_free_game(&game, EXIT_FAILURE), 1);
    // printf("\npass start\n");
    // ft_free_game(&game, EXIT_SUCCESS);
    return (start_game(&game));
}
