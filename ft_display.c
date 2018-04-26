/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:34:45 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/19 16:28:42 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line1(t_env env, t_point p0, t_point d, t_point inc)
{
	int cumul;
	int i;

	i = 1;
	cumul = d.x / 2;
	while (i++ <= d.x)
	{
		p0.x += inc.x;
		cumul += d.y;
		if (cumul >= d.x)
		{
			cumul -= d.x;
			p0.y += inc.y;
		}
		fill_pixel(env, p0.x, p0.y, p0.color);
		p0.color += 0x000001 * 1 * d.color;
	}
}

void	ft_draw_line2(t_env env, t_point p0, t_point d, t_point inc)
{
	int cumul;
	int i;

	i = 1;
	cumul = d.y / 2;
	while (i++ <= d.y)
	{
		p0.y += inc.y;
		cumul += d.x;
		if (cumul >= d.y)
		{
			cumul -= d.y;
			p0.x += inc.x;
		}
		fill_pixel(env, p0.x, p0.y, p0.color);
		p0.color += 0x000001 * 1 * d.color;
	}
}

void	ft_draw_line(t_env env, t_point p0, t_point p1)
{
	t_point d;
	t_point inc;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
	d.color = p1.color - p0.color;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = abs(d.x);
	d.y = abs(d.y);
	if (d.x > d.y)
	{
		if (d.x != 0)
			d.color = d.color / d.x;
		ft_draw_line1(env, p0, d, inc);
	}
	else
	{
		if (d.y != 0)
			d.color = d.color / d.y;
		ft_draw_line2(env, p0, d, inc);
	}
}

void	ft_check_draw(t_env env, int i, int j)
{
	t_point p0;
	t_point p1;

	p0.x = calc_x(j, i, env);
	p0.y = calc_y(j, i, env.map[i][j], env);
	p0.color = get_color(env.map[i][j], env.param.y);
	if (j + 1 < env.size.x)
	{
		p1.x = calc_x(j + 1, i, env);
		p1.y = calc_y(j + 1, i, env.map[i][j + 1], env);
		p1.color = get_color(env.map[i][j + 1], env.param.y);
		ft_draw_line(env, p0, p1);
	}
	if (env.map[i + 1])
	{
		p1.x = calc_x(j, i + 1, env);
		p1.y = calc_y(j, i + 1, env.map[i + 1][j], env);
		p1.color = get_color(env.map[i + 1][j], env.param.y);
		ft_draw_line(env, p0, p1);
	}
}

void	ft_display(t_env env)
{
	int i;
	int j;

	i = 0;
	while (env.map[i])
	{
		j = 0;
		while (j < env.size.x)
		{
			if (env.param.x == 0)
				fill_pixel(env, calc_x(j, i, env),
						calc_y(j, i, env.map[i][j], env),
						get_color(env.map[i][j], env.param.y));
			else
				ft_check_draw(env, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
}
