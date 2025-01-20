#include "so_long.h"

t_coord *find_position(char **arr, char c)
{
    t_coord *new;
    int pos_y;
    char *pos_x;

    new = malloc(sizeof(t_coord));
    if(!new)
        return (NULL);
    pos_y = -1;
    while(arr[++pos_y])
    {
        pos_x = ft_strchr(arr[pos_y], c);
        if(pos_x)
        {
            new->y = pos_y;
            new->x = pos_x - arr[pos_y];
            return (new);
        }
    }
    return (NULL);
}

int ft_arrlen(char **s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

int	screen_size(t_game *game)
{
	int	pc_width;
	int	pc_height;

	pc_width = 0;
	pc_height = 0;
	mlx_get_screen_size(game->mlx, &pc_width, &pc_height);
	if (game->size.x * WIDTH > pc_width)
		return (error_int("Map width - too large"));
	if (game->size.y * HEIGHT > pc_height)
		return (error_int("Map height - too high"));
	return (1);
}
