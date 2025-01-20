#include "so_long.h"

int map_gameboard(char **map)
{
    int y;
    int size_x;
    int i;

    y = ft_arrlen(map);
    size_x = ft_strlen(map[0]);
    i = 0;
    if((size_x < 5 && y < 3) || (size_x < 3 && y < 5))
        return (error_int("Mininum map gameboard - 5x3 | 3x5"));
    while(++i < y)
    {
        if(ft_strlen(map[i]) != (size_t)size_x)
            return (error_int("Map x size not equal"));
    }
    return (1);
}

int board_limits(char ** map)
{
    size_t i;
    size_t size_y;
    size_t size_x;

    i =  0;
    size_x = ft_strlen(map[i]) - 1;
    size_y = ft_arrlen(map) - 1;
    printf("size y : %ld,  size x : %ld", size_y, size_x);
    printf("strspn y : %ld,  strspn x : %ld", ft_strspn(map[0], "1"), (ft_strspn(map[size_y], "1")));
    if ((ft_strspn(map[0], "1") != size_x + 1) || (ft_strspn(map[size_y], "1") != size_x + 1))
        return (error_int("Top | Bottom rows on board limits data incorrect - != 1"));
    while (++i < size_y)
    {
        if(map[i][0] != '1' || map[i][size_x] != '1')
            return (error_int("Left | Right rows on board limits data incorrect - != 1"));
    }
    return (1);
}

char **ft_arrcpy(char **s)
{
    char **cpy;
    int i;

    i = ft_arrlen(s) + 1;
    cpy = (char **)ft_calloc(sizeof(char *), i);
    if(!cpy)
        return(NULL);
    i = -1;
    while(s[++i])
    {
        cpy[i] = ft_strdup(s[i]);
        if(!cpy[i])
            return(ft_free_array(cpy), NULL);
    }
    return (cpy);
}

int flood_fill(char **map, t_coord pos)
{
    int count;
    
    count = 0;
    if (!ft_strspn(&map[pos.y][pos.x], "PEC0"))
        return (0);
    if (map[pos.y][pos.x] == 'C' || map[pos.y][pos.x] == 'E')
		count = 1;
	map[pos.y][pos.x] = 'X';
	count += flood_fill(map, (t_coord){pos.x + 1, pos.y});
	count += flood_fill(map, (t_coord){pos.x - 1, pos.y});
	count += flood_fill(map, (t_coord){pos.x, pos.y + 1});
	count += flood_fill(map, (t_coord){pos.x, pos.y - 1});
	return (count);   
}

int solvable_game(char **map, t_check *ck)
{
    t_coord *player;
    char    **map_cpy;
    int     c_and_e;

    player = find_position(map, 'P');
    if(!player)
        return (error_int("Player not found"));
    map_cpy = ft_arrcpy(map);
    if(!map_cpy)
        return (error_int("Map copy failed"));
    c_and_e = flood_fill(map_cpy, *player);
    free(player);
    ft_free_array(map_cpy);
    if(c_and_e != (ck->c + ck->e))
        return (error_int("Unsolvable game - c | e unreacheble"));
    return (1);
}
