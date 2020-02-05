/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 04:58:33 by nsaber            #+#    #+#             */
/*   Updated: 2020/02/05 05:10:57 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int     test_string_eq(char **argv)
{
    return(!ft_strequ(argv[1], argv[3]));   
}

int     test_cmp(char **argv)
{
    int i;
    
    t_cmp operator[] = {
        {"=",&test_string_eq}
    };
    i = 0;
    while(i < sizeof(operator)/sizeof(*operator))
    {
        if (ft_strequ(argv[2],operator[i].operator))
            return(operator[i].f(argv));
        i++;
    }
    ft_putendl("operator not found");
    return(2);
}