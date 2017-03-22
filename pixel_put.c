/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:51:24 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/02/19 15:09:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int val)
{
	if (val > 0)
		return (val);
	else
		return (-val);
}

void	center_img(t_env *env)
{
	if (!env->pos_x && !env->pos_y)
	{
		env->pos_x = (SCREEN_X / 2) - (env->len_line * env->space / 2);
		env->pos_y = (SCREEN_Y / 2) - (env->nb_line * env->space / 2);
	}
}

int		line_put(t_env env, int x, int y)
{
	if (x > 0 && y > 0 && x < 1600 && y < 900)
	{
		if ((env.z1 > 0 && env.z1 <= 10) || (env.z2 > 0 && env.z2 <= 10))
		{
			env.data[(y * env.size_line) + (x * (env.bpp / 8))] = -env.b;
			env.data[(y * env.size_line) + (x * (env.bpp / 8)) + 1] = -env.g;
			env.data[(y * env.size_line) + (x * (env.bpp / 8)) + 2] = -env.r;
		}
		else
		{
			env.data[(y * env.size_line) + (x * (env.bpp / 8))] = env.b;
			env.data[(y * env.size_line) + (x * (env.bpp / 8)) + 1] = env.g;
			env.data[(y * env.size_line) + (x * (env.bpp / 8)) + 2] = env.r;
		}
	}
	return (0);
}

void	swap_coord(t_env *env)
{
	int tmp;

	tmp = env->x1;
	env->x1 = env->x2;
	env->x2 = tmp;
	tmp = env->y1;
	env->y1 = env->y2;
	env->y2 = tmp;
}

void	displine(t_env *env)
{
	if (ft_abs(env->x2 - env->x1) >= ft_abs(env->y2 - env->y1))
	{
		if (env->x1 < env->x2)
			draw_line_v(*env);
		else
		{
			swap_coord(*(&env));
			draw_line_v(*env);
		}
	}
	else
	{
		if (env->y1 < env->y2)
			draw_line_h(*env);
		else
		{
			swap_coord(*(&env));
			draw_line_h(*env);
		}
	}
}
