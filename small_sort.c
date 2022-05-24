/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:30:53 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 14:22:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	tri_sort_a(t_stack	**stack_a, t_stack **stack_b, t_inst **instruct)
{
	int	b;
	int	c;

	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (b < (*stack_a)->value && (*stack_a)->value < c)
		stack_swap(stack_a, instruct);
	else if ((*stack_a)->value < b && b > c)
	{
		stack_push(stack_b, stack_a, instruct);
		stack_swap(stack_a, instruct);
		stack_push(stack_a, stack_b, instruct);
		if ((*stack_a)->value > c)
			stack_swap(stack_a, instruct);
	}
	else if ((*stack_a)->value > b)
	{
		stack_swap(stack_a, instruct);
		stack_push(stack_b, stack_a, instruct);
		stack_swap(stack_a, instruct);
		stack_push(stack_a, stack_b, instruct);
		if (b > c)
			stack_swap(stack_a, instruct);
	}
}

static void	tri_sort_b(t_stack	**stack_a, t_stack **stack_b, t_inst **instruct)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (c < a && a < b)
		stack_swap(stack_a, instruct);
	stack_push(stack_b, stack_a, instruct);
	if ((a < c && c < b) || (a < b && b < c))
		stack_rotate(stack_b, instruct);
	if ((b < a && a < c) || (a < b && b < c))
		stack_swap(stack_a, instruct);
	stack_push(stack_b, stack_a, instruct);
	if (b < a && a < c)
		stack_swap(stack_b, instruct);
	stack_push(stack_b, stack_a, instruct);
	if ((a < c && c < b) || (a < b && b < c))
		stack_reverse_rotate(stack_b, instruct);
	if (b < c && c < a)
		stack_swap(stack_b, instruct);
}

void	small_stack_sort(t_stack **stack_a, t_stack **stack_b, int size,
			t_inst **instruct)
{
	int	is_a;

	is_a = !('a' - (*stack_a)->name);
	if (size == 1)
	{
		if (!is_a)
			stack_push(stack_b, stack_a, instruct);
		return ;
	}
	if (size == 2)
	{
		if (!is_top_ordered(*stack_a, is_a))
			stack_swap(stack_a, instruct);
		if (!is_a)
		{
			stack_push(stack_b, stack_a, instruct);
			stack_push(stack_b, stack_a, instruct);
		}
		return ;
	}
	if (size == 3 && is_a)
		tri_sort_a(stack_a, stack_b, instruct);
	if (size == 3 && !is_a)
		tri_sort_b(stack_a, stack_b, instruct);
}
