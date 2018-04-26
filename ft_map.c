/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:22:17 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/18 19:04:24 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_alloc(int x, int y)
{
	int **map;
	int i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		if (!(map[i] = (int*)malloc(sizeof(int) * (x))))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		**ft_map(int fd, int x, int y)
{
	char	*line;
	int		**map;
	char	**tab;
	int		i;
	int		j;

	j = 0;
	if (!(map = ft_alloc(x, y)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			map[j][i] = ft_atoi(tab[i]);
			i++;
		}
		free(line);
		ft_free((void**)tab);
		j++;
	}
	free(line);
	close(fd);
	return (map);
}
