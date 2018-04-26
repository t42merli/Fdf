/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:18:37 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/18 15:58:11 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	int bpp;
	int s_l;
	int endian;

	env->img = mlx_new_image(env->mlx, 1920, 1080);
	env->img_string = mlx_get_data_addr(env->img, &bpp, &s_l, &endian);
}

void	fill_pixel(t_env env, int x, int y, int color)
{
	unsigned int color2;

	if (x >= 0 && x < 1920 && y < 1080 && y >= 0)
	{
		color2 = mlx_get_color_value(env.mlx, color);
		ft_memcpy(&env.img_string[4 * 1920 * y + 4 * x], (char*)&color2, 4);
	}
}
