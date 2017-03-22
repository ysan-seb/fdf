/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:56:06 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/01/09 20:00:54 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 4096

typedef struct	s_struct
{
	char		*s[5000];
	int			r;
	char		buf[BUFF_SIZE + 1];
	char		*t;
	char		*t_b;
}				t_struct;

int				get_next_line(int const fd, char **line);

#endif
