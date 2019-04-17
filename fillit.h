/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:28:42 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/17 20:48:25 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_tetra 
{
	int				**int;
	char			id;
	struct s_tetra	*next;
}				t_tetra;

int		parse_input(char *input_path);
int		check_line(char *line, int n);
t_tetra	*add_node(t_tetra *head);
t_tetra *add_block_coord(t_tetra *head, char *line, int n);

#endif
