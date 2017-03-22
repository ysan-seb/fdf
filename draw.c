/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 10:48:45 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/02/19 15:08:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_line_v(t_env env)
{
	int dx;
	int dy;
	int x;
	int y;

	x = env.x1;
	dx = env.x2 - env.x1;
	dy = env.y2 - env.y1;
	while (x <= env.x2 && dx > 0)
	{
		y = env.y1 + dy * (x - env.x1) / dx;
		line_put(env, y + env.pos_x, x + env.pos_y);
		x++;
	}
	return (0);
}

int		draw_line_h(t_env env)
{
	int dx;
	int dy;
	int x;
	int y;

	y = env.y1;
	dx = env.x2 - env.x1;
	dy = env.y2 - env.y1;
	while (y <= env.y2 && dy > 0)
	{
		x = env.x1 + dx * (y - env.y1) / dy;
		line_put(env, y + env.pos_x, x + env.pos_y);
		y++;
	}
	return (0);
}

void	converting_coord(t_env *env)
{
	env->x1 *= env->space;
	env->y1 *= env->space;
	env->x2 *= env->space;
	env->y2 *= env->space;
	env->x1 += env->z1;
	env->y1 += env->z1;
	env->x2 += env->z2;
	env->y2 += env->z2;
	env->x2 += env->z;
	env->y2 += env->z;
}

int		line_tab_x(t_env env)
{
	int x;
	int y;
	int z;

	x = 0;
	while (x < env.nb_line)
	{
		y = 0;
		while (y < env.len_line)
		{
			env.z1 = env.tab[x][y];
			env.z2 = ((y + 1) < env.len_line) ? env.tab[x][y + 1] : env.z1;
			env.x1 = x;
			env.y1 = y;
			env.x2 = x;
			env.y2 = ((y + 1) < env.len_line) ? y + 1 : y;
			converting_coord(&env);
			displine(&env);
			y++;
		}
		x++;
	}
	line_tab_y(env);
	return (0);
}

int		line_tab_y(t_env env)
{
	int x;
	int y;
	int z;

	y = 0;
	while (y < env.len_line)
	{
		x = 0;
		while (x < env.nb_line)
		{
			env.z1 = env.tab[x][y];
			env.z2 = ((x + 1) < env.nb_line) ? env.tab[x + 1][y] : env.z1;
			env.x1 = x;
			env.y1 = y;
			env.x2 = ((x + 1) < env.nb_line) ? x + 1 : x;
			env.y2 = y;
			converting_coord(&env);
			displine(&env);
			x++;
		}
		y++;
	}
	return (0);
}
