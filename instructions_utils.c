/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:01:00 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 14:47:21 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	free_instr(t_inst **instr)
{
	if ((*instr)->next)
	{
		(*instr) = (*instr)->next;
		free((*instr)->previous);
	}
	else
	{
		free(*instr);
		*instr = NULL;
	}
}

int	new_instr(t_inst **instruct, int execution)
{
	t_inst	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (1);
	new->exec = execution;
	new->next = NULL;
	new->previous = *instruct;
	if (*instruct == NULL)
		*instruct = new;
	else
	{
		while (new->previous->next)
			new->previous = new->previous->next;
		new->previous->next = new;
	}
	return (0);
}

void	printf_free_instr(t_inst *instr)
{
	char	*value;

	value = NULL;
	while (instr)
	{
		if (instr->exec == 1)
			value = "pa";
		if (instr->exec == -1)
			value = "pb";
		if (instr->exec == 2)
			value = "ra";
		if (instr->exec == 3)
			value = "rb";
		if (instr->exec == -2)
			value = "rra";
		if (instr->exec == -3)
			value = "rrb";
		if (instr->exec == 4)
			value = "sa";
		if (instr->exec == 5)
			value = "sb";
		ft_printf("%s\n", value);
		free_instr(&instr);
	}
}
