#include "so_long.h"

char **error_arr(char *s)
{
    if(s)
        ft_printf("Error\n%s\n", s);
    return (NULL);
}

char *error_str(char *s)
{
    if(s)
        ft_printf("Error\n%s\n", s);
    return (NULL);
}

int error_int(char *s)
{
    if(s)
        ft_printf("Error\n%s\n", s);
    return (0);
}

void error_void(char *s)
{
    if(s)
        ft_printf("Error\n%s\n", s);
}