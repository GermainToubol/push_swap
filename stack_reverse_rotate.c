/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:20:30 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/20 17:56:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

void	stack_reverse_rotate(t_stack **stack, t_inst **instruct)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	tmp = *stack;
	if (tmp->name == 'a')
		new_instr(instruct, -2);
	else
		new_instr(instruct, -3);
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
