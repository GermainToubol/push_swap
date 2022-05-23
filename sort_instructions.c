/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:51:34 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 15:58:06 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	clean_instructions(t_inst **instructions)
{
	t_inst	*tmp;

	tmp = *instructions;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->exec + tmp->next->exec == 0)
		{
			if (tmp->previous != NULL)
				tmp->previous->next = tmp->next->next;
			else
				*instructions = tmp->next->next;
			if (tmp->next->next != NULL)
				tmp->next->next->previous = tmp->previous;
			free(tmp->next);
			free(tmp);
			tmp = *instructions;
			continue ;
		}
		tmp = tmp->next;
	}
}

void	change_instructions(t_inst	**instructions)
{
	t_inst	*tmp;
	int		cleaned;

	tmp = *instructions;
	while (tmp && tmp->next && tmp->next->next)
	{
		cleaned = 1;
		if (tmp->exec == 2 && tmp->next->exec == -1
			&& tmp->next->next->exec == -2)
			tmp->exec = 4;
		else if (tmp->exec == 3 && tmp->next->exec == 1
				 && tmp->next->next->exec == -3)
			tmp->exec = 5;
		else
			cleaned = 0;
		if (cleaned)
		{
			tmp = tmp->next->next;
			tmp->previous->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->previous = tmp->previous;
			free(tmp);
			tmp = *instructions;
			continue ;
		}
		tmp = tmp->next;
	}
}
