/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:58:33 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/21 19:42:00 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int altitude, int color)
{
	if (color == 1)
		return (0XFFFFFF - 0x000101 * (abs(altitude) * 10));
	return (0XFFFFFF);
}

int		calc_x(int xo, int y, t_env env)
{
	double x;

	x = env.translation.x + env.scale * (cos(env.omega * 0.0174533) * xo +
			sin(env.omega * 0.0174533) * y);
	return ((int)x);
}

int		calc_y(int x, int yo, int z, t_env env)
{
	double y;

	y = env.translation.y + env.scale * (sin(env.alpha * 0.0174533)
			* (sin(env.omega * 0.0174533) * x -
				cos(env.omega * 0.0174533) * yo) + cos(env.alpha * 0.0174533)
			* z);
	return ((int)y);
}
