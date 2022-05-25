/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:05:37 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 09:51:37 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"

void	stack_swap(t_stack **stack, t_inst **instruct)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	tmp = *stack;
	if (tmp->name == 'a')
		new_instr(instruct, 4);
	else
		new_instr(instruct, 5);
	(*stack) = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
