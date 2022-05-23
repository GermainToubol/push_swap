/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:23:42 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 18:43:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_stack **stack, int size, t_inst **instruct)
{
	t_stack	*tmp;
	int i;

	i = 0;
	tmp = *stack;
	while (i < size)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		stack_reverse_rotate(stack, instruct);
		i++;
	}
}

int	isclean_median(t_stack	*stack, int size, int is_a, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_a && stack->value < pivot)
			return (0);
		if (!is_a && stack->value > pivot)
			return (0);
		i++;
		stack = stack->next;
	}
	return (1);
}

void	divide(t_stack **stack_a, t_stack **stack_b, int size, t_inst **instruct)
{
	int	pivot;
	int	size_a;
	int	size_b;
	int	i;
	int is_a;

	if (*stack_a == NULL)
		return ;
	is_a = !('a' - (*stack_a)->name);
	if (stack_n_sorted(*stack_a, size, is_a))
		return ;
	if (size == 2)
	{
		if (!is_top_ordered(*stack_a, is_a))
			stack_swap(stack_a, instruct);
		//merge(stack_a, stack_b, 2, instruct);
		return ;
	}
	pivot = median(*stack_a, size);
	i = 0;
	size_a = 0;
	size_b = 0;
	while (i < size)
	{
		if ((is_a && ((*stack_a)->value < pivot))
			|| (!is_a && (*stack_a)->value > pivot))
		{
			stack_push(stack_b, stack_a, instruct);
			size_b++;
		}
		else
		{
			stack_rotate(stack_a, instruct);
			size_a++;
		}
		i++;
	}
	reverse_rotate(stack_a, size_a, instruct);
	divide(stack_a, stack_b, size_a, instruct);
	merge(stack_a, stack_b, size_b, instruct);
}
