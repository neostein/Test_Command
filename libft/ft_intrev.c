/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:58:24 by nsaber            #+#    #+#             */
/*   Updated: 2018/10/17 19:12:08 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intrev(int k)
{
	int a;

	while (k >= 10)
	{
		a = k % 10 + '0';
		write(1, &a, 1);
		k = k / 10;
	}
	a = k + '0';
	write(1, &a, 1);
}
