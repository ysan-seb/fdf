/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 10:45:16 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/02/19 15:13:19 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			cmd_key(int key, t_env *env)
{
	(key == 78) ? env->space -= 1 : env->space;
	(key == 69) ? env->space += 1 : env->space;
	(key == 13) ? env->pos_y -= 50 : env->pos_y;
	(key == 1) ? env->pos_y += 50 : env->pos_y;
	(key == 2) ? env->pos_x += 50 : env->pos_x;
	(key == 0) ? env->pos_x -= 50 : env->pos_x;
	(key == 15) ? env->r += 5 : env->r;
	(key == 5) ? env->g += 5 : env->g;
	(key == 11) ? env->b += 5 : env->b;
	(key == 116) ? env->z += 1 : env->z;
	(key == 121) ? env->z -= 1 : env->z;
	if (key == 53)
		exit(EXIT_SUCCESS);
	mlx_destroy_image(env->mlx, env->img);
	fdf_init(env);
	return (0);
}

int			fdf_init(t_env *env)
{
	check_file(env, env->argv);
	center_img(env);
	env->img = mlx_new_image(env->mlx, SCREEN_X, SCREEN_Y);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	line_tab_x(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void		color_init(t_env *env)
{
	env->b = 50;
	env->g = 50;
	env->r = 50;
	env->z = 0;
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		x;
	int		y;

	color_init(&env);
	env.argv = argv[1];
	env.space = 35;
	if (argc != 2)
		print_error_type("usage: ./a.out [ Map_missing ]\n");
	else
	{
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, argv[1]);
		fdf_init(&env);
		mlx_hook(env.win, KEYPRESS, KEYPRESSMASK, cmd_key, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
