#include "so_long.h"

char **create_map(char *s_map, t_check *ck)
{
	char	**map;

	map = ft_split(s_map, '\n');
	if (!map)
		return (error_arr("Map string split failed"));
	if (!map_gameboard(map) || !board_limits(map) || !solvable_game(map, ck))
		return (ft_free_array(map), NULL);
	return (map);
}

int map_content(char *s_map, t_check *ck)
{
	int	i;

	i = -1;
	while (s_map[++i])
	{
		if ((s_map[0] != '1') || (s_map[i] == '\n' && s_map[i + 1] == '\n'))
			return (error_int("Map content - start != 1 | n aside | invalid data"));
		else if (s_map[i] == '\n')
			ck->n++;
		else if (s_map[i] == 'P')
			ck->p++;
		else if (s_map[i] == 'E')
			ck->e++;
		else if (s_map[i] == 'C')
			ck->c++;
		else if (s_map[i] == '1' || s_map[i] == '0')
			continue ;
		else
			return (error_int("Map content - invalid data\n"));
	}
	if(s_map[i - 2] != '1' || ck->n < 2 || ck->p !=1 || ck->e != 1 || ck->c < 1)
		return (error_int("Map content - end, p or e != 1 | n < 2 | c < 1"));
	return (1);
}


char *create_map_buff(int fd)
{
    char    *s_map;
    char    *buff;
	char	*tmp;

    s_map = NULL;
    buff = get_next_line(fd);
    if (!buff)
        return (error_str("Empty map"));
    while (buff)
    {
		tmp = NULL;
        if (s_map)
        {
            tmp = ft_strjoin(s_map, buff);
            free(s_map);
            free(buff);
            s_map = tmp;
        }
        else
        {
            s_map = buff;
        }
        if (!s_map)
            return (error_str("Line creation process fail"));
        buff = get_next_line(fd);
    }
	return (s_map);
}

char **check_map(char *f_map, t_check *ck)
{
	int		fd;
	char	*map_buff;
	char	**map;

	if (ft_strlen(f_map) < 5 || ft_strcmp(&f_map[ft_strlen(f_map) - 4], ".ber"))
		return (error_arr("Map file syntax incorrect"));
	fd = open(f_map, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nOpen map file failed\n"), NULL);
	map_buff = create_map_buff(fd);
	if (close(fd) == -1)
		return (perror("Error\nClose map file failed\n"), free(map_buff), NULL);
	if (!map_buff)
		return (error_arr("Create map buff from map file failed"));
	if(ft_strlen(map_buff) < 17)
		return (free(map_buff), error_arr("Map smaller than 17 caracters"));
	if (!map_content(map_buff, ck))
		return (free(map_buff), NULL);
	map = create_map(map_buff, ck);
	if(!map)
		return (ft_free_array(map), free(map_buff), NULL);
	free(map_buff);
	return (map);
}
