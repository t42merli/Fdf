/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:59:45 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/21 18:46:36 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	if (keycode >= 123 && keycode <= 126)
		ft_rotate((t_env *)param, keycode);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		ft_move((t_env*)param, keycode);
	if (keycode == 69 || keycode == 78)
		ft_zoom((t_env*)param, keycode);
	if (keycode == 8 || keycode == 65)
		ft_param((t_env*)param, keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		check_line(char *line, int x)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-')
			{
				ft_free((void**)tab);
				return (-1);
			}
			j++;
		}
		i++;
	}
	ft_free((void**)tab);
	if (i != x && x != 0)
		return (-1);
	return (i);
}

t_point	get_size(int fd)
{
	char	*line;
	t_point	win;

	win.x = 0;
	win.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((win.x = check_line(line, win.x)) == -1)
		{
			free(line);
			return (win);
		}
		free(line);
		win.y++;
	}
	free(line);
	close(fd);
	return (win);
}

void	setup_env(t_env *env)
{
	env->scale = 21;
	env->omega = 340;
	env->alpha = 265;
	env->translation.x = 960 - env->size.x;
	env->translation.y = 540 - env->size.y;
	env->param.x = 1;
	env->param.y = 1;
	env->map = ft_map(env->fd, env->size.x, env->size.y);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1920, 1080, "fdf");
	create_image(env);
}

int		main(int argc, char *argv[])
{
	t_env env;

	env.fd = open(argv[1], O_RDONLY);
	if (env.fd == -1 || argc != 2)
	{
		ft_putendl("usage : ./fdf file");
		return (0);
	}
	env.size = get_size(env.fd);
	if (env.size.x == -1 || env.size.y == 0)
	{
		ft_putendl("error file");
		return (0);
	}
	env.fd = open(argv[1], O_RDONLY);
	setup_env(&env);
	ft_display(env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
