/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 10:59:20 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/02/19 15:21:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# define SCREEN_X 1600
# define SCREEN_Y 900
# define KEYPRESS 2
# define KEYPRESSMASK (1L << 0)

typedef struct		s_env
{
	int				nb_line;
	int				len_line;
	int				len_cmp;
	int				file;
	char			*line;
	char			**line_split;
	int				**tab;
	char			*argv;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	char			*data;
	int				size_line;
	int				bpp;
	int				endian;
	int				key;
	int				pos_x;
	int				pos_y;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				space;
	char			r;
	char			g;
	char			b;
	char			z;
}					t_env;

void				print_error_type(char *type);
void				center_img(t_env *env);
int					check_file(t_env *env, char *argv);
int					get_len_line_split(char **line_split);
int					**get_tab(int nb_line, int len_line);
int					**write_tab(int **tab, t_env *env, char *argv);
int					line_tab_x(t_env env);
int					line_tab_y(t_env env);
int					draw_line_h(t_env env);
int					draw_line_v(t_env env);
void				displine(t_env *env);
void				swap_coord(t_env *env);
int					ft_abs(int val);
void				converting_coord(t_env *env);
int					fdf_init(t_env *env);
int					line_put(t_env env, int x, int y);

#endif
