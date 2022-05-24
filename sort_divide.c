/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:23:42 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 14:45:42 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_stack **stack, int size, t_inst **instruct)
{
	t_stack	*tmp;
	int		i;

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

static int	stack_split(t_stack **stack_a, t_stack **stack_b, int size,
					t_inst **instruct)
{
	int	pivot;
	int	size_a;
	int	is_a;
	int	i;

	pivot = median(*stack_a, size);
	is_a = !('a' - (*stack_a)->name);
	i = 0;
	size_a = 0;
	while (i++ < size)
	{
		if ((is_a && ((*stack_a)->value < pivot))
			|| (!is_a && (*stack_a)->value >= pivot))
			stack_push(stack_b, stack_a, instruct);
		else
		{
			stack_rotate(stack_a, instruct);
			size_a++;
		}
	}
	return (size_a);
}

void	divide(t_stack **stack_a, t_stack **stack_b, int size,
				t_inst **instruct)
{
	int	size_a;
	int	is_a;

	if (*stack_a == NULL || size == 0)
		return ;
	is_a = !('a' - (*stack_a)->name);
	if (stack_n_sorted(*stack_a, size, is_a))
	{
		while (!is_a && size-- > 0)
			stack_push(stack_b, stack_a, instruct);
		return ;
	}
	if (size <= 3)
		return (small_stack_sort(stack_a, stack_b, size, instruct));
	size_a = stack_split(stack_a, stack_b, size, instruct);
	reverse_rotate(stack_a, size_a, instruct);
	if (is_a)
		divide(stack_a, stack_b, size_a, instruct);
	if (is_a)
		divide(stack_b, stack_a, size - size_a, instruct);
	if (!is_a)
		divide(stack_b, stack_a, size - size_a, instruct);
	if (!is_a)
		divide(stack_a, stack_b, size_a, instruct);
}
