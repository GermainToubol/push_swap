/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:14:53 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 09:50:42 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

t_stack	*stack_new(t_stack **stack, int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(*new));
	new->value = value;
	if (new == NULL)
		return (NULL);
	new->next = *stack;
	new->name = '0';
	*stack = new;
	return (*stack);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	stack_n_sorted(t_stack *stack, int size, int grow)
{
	int	i;

	if (size < 2)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (grow && stack->value > stack->next->value)
			return (0);
		if (!grow && stack->value < stack->next->value)
			return (0);
		i++;
		stack = stack->next;
	}
	return (1);
}
