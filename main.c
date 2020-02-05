/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:04:38 by nsaber            #+#    #+#             */
/*   Updated: 2020/02/05 05:09:37 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int builtin_test_1(char *str, int len)
{
    if (len == 0 || str[0] == '\0')
        return(1);
    return(0);
}

int builtin_test_2(char **argv)
{
    printf("working on it, [options]\n");
    return(test_options(argv));
}

int builtin_test_3(char **argv)
{
    printf("comparaison between strings\n");
    return(test_cmp(argv));
}

int builtin_test_4(char **argv)
{
    printf("why it reach 4 args ?\n");
    exit(1);
    return(0);
}

int builtin_test(int len , char **argv)
{
    int ret;

    if (len <= 1)
    {
        ret = builtin_test_1(argv[len], len);
    }
    else if (len == 2)
    {
       ret = builtin_test_2(argv);
    }
    else if (len == 3)
    {
        ret = builtin_test_3(argv);
    }
    else
    {
        printf("else\n");
        ret = builtin_test_4(argv);
    }
    
    return(ret);
}

int     ft_arraylen(char **argv) // must be in libft
{
    int i = 0;
    while(*argv)
    {
        argv++;
        i++;
    }
    return(i);
}

int main(int argc, char **argv)
{
    int ret;
    int arraylen;

    arraylen = ft_arraylen(argv + 1);
    ret = builtin_test(arraylen - 1, argv + 1); // we send "test" in argv , and the exact number 
    printf("return : %d\n",ret);

    
    return(0);
}