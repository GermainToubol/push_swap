/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:51:34 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/20 18:02:26 by gtoubol          ###   ########.fr       */
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
