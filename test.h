#ifndef TEST_H
# define TEST_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct  s_option
{
    char    *option;
    int     (*f)(char **argv);
}               t_option;

char	file_type(mode_t st_mode);
int     test_options(char **argv);
int     check_STGID(mode_t st_mode);
int     check_read(mode_t st_mode);

#endif