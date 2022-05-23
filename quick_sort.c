/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:30:56 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 18:59:06 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

void	merge(t_stack **stack_a, t_stack **stack_b, int size, t_inst **instruct)
{
	int	i;
	int	is_a;

	if (size == 0)
		return ;
	is_a = !('a' - (*stack_a)->name);
	if (!stack_n_sorted(*stack_b, size, !is_a))
		divide(stack_b, stack_a, size, instruct);
	i = 0;
	while (i < size)
	{
		if (*stack_a == NULL
			|| (is_a && (*stack_a)->value > (*stack_b)->value)
			|| (!is_a && (*stack_a)->value < (*stack_b)->value))
			stack_push(stack_a, stack_b, instruct);
		else
		{
			stack_push(stack_a, stack_b, instruct);
			stack_swap(stack_a, instruct);
		}
		i++;
	}
}


void	merge2(t_stack **stack_a, t_stack **stack_b, int size, t_inst **instruct)
{
	int i;
	int	is_a;

	if (size == 0 || *stack_b == NULL)
		return ;
	is_a = !('a' - (*stack_a)->name);
	if (is_a && !stack_n_sorted(*stack_b, size, !is_a))
		divide(stack_b, stack_a, size, instruct);
	i = 0;
	if (size == 1)
	{
		stack_push()
	}
	while (i < size)
	{
		if (*stack_a == NULL
			|| (is_a && (*stack_a)->value > (*stack_b)->value)
			|| (!is_a && (*stack_a)->value < (*stack_b)->value))
			stack_push(stack_a, stack_b, instruct);
		else
		{
			stack_push(stack_a, stack_b, instruct);
			stack_swap(stack_a, instruct);
		}
		i++;
	}
}
