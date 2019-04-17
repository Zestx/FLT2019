/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:40:21 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/17 20:53:17 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*add_node(t_tetra *head)
{
	t_tetra *new_node;
	t_tetra	*roam;

	if (!(new_node = malloc(sizeof(new_node))))
		return (NULL);
	if (!(new_node->coord = malloc(sizeof(int*) * 5)))
	new_node->coord[4] = NULL;
	new_node->id = 0;
	new_node->next = NULL;
	if (!head)
	{
		head = new_node;
		return (head);
	}
	roam = head;
	while (roam->next)
		roam = roam->next;
	roam->next = new_node;
	return (head);
}

int			*look_for_block(char *line, int count)
{

}

t_tetra		*add_block_coord(t_tetra *head, int x, int y, int n)
{
	t_tetra *roam;

	roam = head;
	while (roam->next)
		roam = roam->next;

	if (!(roam->coord[n] = malloc(sizeof(int) * 2)))
		return (NULL);
	rooam->coord[n][0] = 
	rooam->coord[n][1] = 

	return (head);
}
