/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:14:53 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 14:37:23 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

t_stack	*stack_new(t_stack **stack, int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(*new));
	new->value = value;
	if (new == NULL)
		return (NULL);
	new->next = *stack;
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
