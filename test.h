#ifndef TEST_H
# define TEST_H

#include "libft/libft.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_option
{
    char    *option;
    int     (*f)(char **argv);
}               t_option;

char	file_type(mode_t st_mode);
int     test_options(char **argv);

#endif