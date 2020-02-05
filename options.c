/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 01:23:31 by nsaber            #+#    #+#             */
/*   Updated: 2020/02/05 01:59:34 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int    test_options_b(char **argv)
{
    return(10);
}

int test_options(char **argv)
{
    int i;
    
    t_option table[] = {
        {"-b",&test_options_b}};

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

