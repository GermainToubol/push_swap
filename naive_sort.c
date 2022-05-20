/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:45:27 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/20 12:28:25 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

int is_sorted(t_stack *stack)
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

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	if (!is_sorted(*stack_a))
	{
		stack_push(stack_b, stack_a);
		ft_printf("pb\n");
		sort_stack(stack_a, stack_b);
	}
	sorted_insert(stack_a, stack_b);
}

void	sorted_insert(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	if (*stack_a == NULL || (*stack_a)->value > (*stack_b)->value)
	{
		stack_push(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else
	{
		stack_push(stack_b, stack_a);
		ft_printf("pb\n");
		stack_rotate(stack_b);
		ft_printf("rb\n");
		sorted_insert(stack_a, stack_b);
		stack_reverse_rotate(stack_b);
		ft_printf("rrb\n");
		stack_push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
