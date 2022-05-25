/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 09:51:32 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"

void	stack_rotate(t_stack **stack, t_inst **instruct)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	tmp = *stack;
	if (tmp->name == 'a')
		new_instr(instruct, 2);
	else
		new_instr(instruct, 3);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = first;
}
