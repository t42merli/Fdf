/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:01:24 by tmerli            #+#    #+#             */
/*   Updated: 2017/12/19 16:27:38 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct	s_point
{
	int x;
	int y;
	int color;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		fd;
	int		omega;
	int		alpha;
	t_point	size;
	t_point	translation;
	int		scale;
	int		**map;
	void	*img;
	char	*img_string;
	t_point param;
}				t_env;

void			ft_free(void **tab);
int				**ft_map(int fd, int x, int y);
void			ft_display(t_env env);
int				calc_x(int xo, int y, t_env env);
int				calc_y(int x, int yo, int z, t_env env);
void			create_image(t_env *env);
void			fill_pixel(t_env env, int x, int y, int color);
void			ft_rotate(t_env *env, int keycode);
void			ft_move(t_env *env, int keycode);
void			ft_zoom(t_env *env, int keycode);
void			ft_param(t_env *env, int keycode);
int				get_color(int altitude, int color);

#endif
