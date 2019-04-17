/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:28:12 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/17 20:48:08 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line, int n)
{
	int i;
	int count;

	if (n % 5 == 0)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
			return (0);
		else
			return (-1);
	}
	if (ft_strlen(line) != 5)
		return (-1);
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		if (line[i] == '#')
			count++;
		i++;
	}
	if (line[i] != '\n')
		return (-1);
	return (count);
}

int		parse_input(char *input_path)
{
	int		i;
	int		fd;
	int 	count;
	int		tmp;
	char	*line;
	t_tetra *head;
	t_tetra *ptr;

	head = NULL;
	head = add_node(head);
	ptr = head;
	count = 0;
	if ((fd = open(input_path, O_RDONLY)) < 0)
		return (-1);
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if ((tmp = check_line(line, i)) < 0)
			return (-1);
		count += tmp;
		if (count > 4)
			return (-1);
		if (i % 5 == 0)
		{
			head = add_node(head);
			ptr = ptr->next;
			count = 0;
			continue ;
		}
		// ADD LINE TO THE CURRENT NODE.
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <input>\n");
		return (0);
	}
	if (parse_input(argv[1]) < 0)
	{
		ft_putstr("error.\n");
		return (1);
	}
	return (0);
}
