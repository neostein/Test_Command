/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaber <nsaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 01:34:18 by nsaber            #+#    #+#             */
/*   Updated: 2020/02/05 03:59:03 by nsaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	file_type(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('?');
}

int     check_read(mode_t st_mode)
{
	return (((st_mode & S_IRUSR) && (st_mode & S_IRGRP)
				&& (st_mode & S_IROTH)) ? 1 : 0);
}


int     check_STGID(mode_t st_mode)
{
    return((st_mode & S_ISGID) ? 1 : 0);
}

