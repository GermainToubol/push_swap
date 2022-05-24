/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:55:13 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 16:08:37 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	naif3(t_stack **stack, int size, t_inst **instruct)
{
	int	test;

	test = stack_n_sorted(*stack, size, 1);
	while (!test)
	{
		if ((*stack)->value > (*stack)->next->value)
			stack_swap(stack, instruct);
		else
			stack_reverse_rotate(stack, instruct);
		test = stack_n_sorted(*stack, size, 1);
	}
}

static void	insert_small(t_stack **stack_a, t_stack **stack_b, int size,
				t_inst **instruct)
{
	while ((*stack_a)->value < (*stack_b)->value)
		stack_rotate(stack_a, instruct);
	stack_push(stack_a, stack_b, instruct);
	while (!stack_n_sorted(*stack_a, size, 1))
		stack_reverse_rotate(stack_a, instruct);
}

static void	insert_big(t_stack **stack_a, t_stack **stack_b, int size,
				t_inst **instruct)
{
	stack_reverse_rotate(stack_a, instruct);
	while ((*stack_a)->value > (*stack_b)->value)
		stack_reverse_rotate(stack_a, instruct);
	stack_rotate(stack_a, instruct);
	stack_push(stack_a, stack_b, instruct);
	while (!stack_n_sorted(*stack_a, size, 1))
		stack_rotate(stack_a, instruct);
}

void	insert_naif(t_stack **stack_a, t_stack **stack_b, int size,
			t_inst **instruct)
{
	int	i;

	i = 0;
	while (i < size - 3)
	{
		stack_push(stack_b, stack_a, instruct);
		i++;
	}
	naif3(stack_a, 3, instruct);
	i = 0;
	while (i++ < size - 3)
	{
		if ((*stack_b)->value < stack_min(*stack_a)
			|| (*stack_b)->value > stack_max(*stack_a))
		{
			stack_push(stack_a, stack_b, instruct);
			if (!stack_n_sorted(*stack_a, i + 3, 1))
				stack_rotate(stack_a, instruct);
			continue ;
		}
		if ((*stack_b)->value < median(*stack_a, i + 2))
			insert_small(stack_a, stack_b, i + 3, instruct);
		else
			insert_big(stack_a, stack_b, i + 3, instruct);
	}
}
