/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:45:27 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 18:03:45 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		stack_push(stack_b, stack_a);
		sort_stack(stack_a, stack_b);
		sorted_insert(stack_a, stack_b);
	}
}

void	sorted_insert(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	if (*stack_a == NULL || (*stack_a)->value > (*stack_b)->value)
		stack_push(stack_a, stack_b);
	else
	{
		stack_push(stack_b, stack_a);
		stack_rotate(stack_b);
		sorted_insert(stack_a, stack_b);
		stack_reverse_rotate(stack_b);
		stack_push(stack_a, stack_b);
	}
}
