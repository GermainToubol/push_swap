/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:45:27 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 13:11:05 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_inst **instruct)
{
	if (*stack_a == NULL)
		return ;
	if (!is_sorted(*stack_a))
	{
		stack_push(stack_b, stack_a, instruct);
		sort_stack(stack_a, stack_b, instruct);
	}
	sorted_insert(stack_a, stack_b, instruct);
}

void	sorted_insert(t_stack **stack_a, t_stack **stack_b, t_inst **instruct)
{
	if (*stack_b == NULL)
		return ;
	if (*stack_a == NULL || (*stack_a)->value > (*stack_b)->value)
		stack_push(stack_a, stack_b, instruct);
	else
	{
		stack_push(stack_b, stack_a, instruct);
		stack_rotate(stack_b, instruct);
		sorted_insert(stack_a, stack_b, instruct);
		stack_reverse_rotate(stack_b, instruct);
		stack_push(stack_a, stack_b, instruct);
	}
}
