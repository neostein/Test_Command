/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 01:23:31 by nsaber            #+#    #+#             */
/*   Updated: 2020/02/05 04:11:13 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int    test_options_b(char **argv)
{
    struct stat buf;
    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 'b')
        return(1);
    return(0);
}

int    test_options_c(char **argv)
{
    struct stat buf;
    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 'c')
        return(1);
    return(0);
}

int    test_options_d(char **argv)
{
    struct stat buf;
    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 'd')
        return(1);
    return(0);
}

int    test_options_e(char **argv)
{
    struct stat buf;
    if (lstat(argv[2],&buf) == -1)
        return(1);
    return(0);
}

int    test_options_f(char **argv)
{
    struct stat buf;
    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != '-')
        return(1);
    return(0);
}

int    test_options_g(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || !check_STGID(buf.st_mode))
        return(1);
    return(0);
}

int    test_options_l(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 'l')
        return(1);
    return(0);
}

int    test_options_p(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 'p')
        return(1);
    return(0);
}

int    test_options_r(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || !check_read(buf.st_mode))
        return(1);
    return(0);
}

int    test_options_capital_s(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || file_type(buf.st_mode) != 's')
        return(1);
    return(0);
}

int    test_options_s(char **argv)
{
    struct stat buf;

    if (lstat(argv[2],&buf) == -1 || buf.st_size <= 0)
        return(1);
    return(0);
}

int test_options(char **argv)
{
    int i;
    
    t_option table[] = {
        {"-b",&test_options_b},
        {"-c",&test_options_c},
        {"-d",&test_options_d},
        {"-e",&test_options_e},
        {"-f",&test_options_f},
        {"-g",&test_options_g},
        {"-L",&test_options_l},
        {"-p",&test_options_p},
        {"-r",&test_options_r},
        {"-S",&test_options_capital_s},
        {"-s",&test_options_s}
        };

    i = 0;
    while(i < sizeof(table)/sizeof(*table))
    {
        if (ft_strequ(table[i].option, argv[1]))
            return(table[i].f(argv));
            i++;
    }
    printf("option not found");
    return(2);
}

