/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 10:49:50 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/02/19 15:08:28 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error_type(char *type)
{
	ft_putstr(type);
	exit(EXIT_FAILURE);
}

int		**write_tab(int **tab, t_env *env, char *argv)
{
	int x;
	int y;

	x = 0;
	env->file = open(argv, O_RDONLY);
	while ((get_next_line(env->file, &env->line) > 0) && x < env->nb_line)
	{
		y = 0;
		env->line_split = ft_strsplit(env->line, ' ');
		while (y < env->len_line)
		{
			tab[x][y] = ft_atoi(env->line_split[y]);
			y++;
		}
		x++;
	}
	close(env->file);
	return (tab);
}

int		**get_tab(int nb_line, int len_line)
{
	int **tab;
	int index;

	index = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line + 1)))
		print_error_type("Error : Dynamic table allocation problem.");
	while (index < nb_line)
	{
		if (!(tab[index] = (int *)malloc(sizeof(int) * len_line + 1)))
			print_error_type("Error : Dynamic table allocation problem.");
		index++;
	}
	tab[index] = NULL;
	return (tab);
}

int		get_len_line_split(char **line_split)
{
	int index;

	index = 0;
	while (line_split[index])
		index++;
	return (index);
}

int		check_file(t_env *env, char *argv)
{
	env->nb_line = 0;
	env->len_line = 0;
	env->len_cmp = 0;
	env->file = open(argv, O_RDONLY);
	while ((get_next_line(env->file, &env->line)) > 0)
	{
		env->line_split = ft_strsplit(env->line, ' ');
		if (!env->len_cmp)
			env->len_cmp = get_len_line_split(env->line_split);
		env->len_line = get_len_line_split(env->line_split);
		if (env->len_line != env->len_cmp)
			print_error_type("Error : Invalid map.\n");
		env->nb_line++;
	}
	close(env->file);
	env->tab = get_tab(env->nb_line, env->len_line);
	env->tab = write_tab(env->tab, env, argv);
	return (0);
}
