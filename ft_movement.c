/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:16:50 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/19 16:24:09 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_env *env, int keycode)
{
	if (keycode == 13)
		env->translation.y -= 20;
	if (keycode == 1)
		env->translation.y += 20;
	if (keycode == 0)
		env->translation.x -= 20;
	if (keycode == 2)
		env->translation.x += 20;
	mlx_destroy_image(env->mlx, env->img);
	create_image(env);
	ft_display(*env);
}

void	ft_rotate(t_env *env, int keycode)
{
	if (keycode == 126)
		env->alpha -= 5;
	if (keycode == 125)
		env->alpha += 5;
	if (keycode == 123)
		env->omega -= 5;
	if (keycode == 124)
		env->omega += 5;
	mlx_destroy_image(env->mlx, env->img);
	create_image(env);
	ft_display(*env);
}

void	ft_zoom(t_env *env, int keycode)
{
	if (keycode == 69)
		env->scale += 1;
	if (keycode == 78)
	{
		if (env->scale > 1)
			env->scale -= 1;
	}
	mlx_destroy_image(env->mlx, env->img);
	create_image(env);
	ft_display(*env);
}

void	ft_param(t_env *env, int keycode)
{
	if (keycode == 8 && env->param.y == 0)
		env->param.y = 1;
	else if (keycode == 8 && env->param.y == 1)
		env->param.y = 0;
	else if (keycode == 65 && env->param.x == 0)
		env->param.x = 1;
	else if (keycode == 65 && env->param.x == 1)
		env->param.x = 0;
	mlx_destroy_image(env->mlx, env->img);
	create_image(env);
	ft_display(*env);
}
