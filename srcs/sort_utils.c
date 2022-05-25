/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:23:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 09:56:50 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int	is_top_ordered(t_stack *stack, int grow)
{
	if (grow && stack->value < stack->next->value)
		return (1);
	if (!grow && stack->value > stack->next->value)
		return (1);
	return (0);
}

int	inter_mid(t_stack *stack, int size)
{
	int	min;
	int	max;

	if (size == 0)
		return (0);
	min = stack->value;
	max = stack->value;
	while (1 && stack != NULL)
	{
		if (max < stack->value)
			max = stack->value;
		else if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return ((max + min) / 2);
}

void	int_sort(int *value, int size)
{
	int	i;
	int	min;

	if (size == 0)
		return ;
	i = 0;
	min = value[0];
	while (i < size)
	{
		if (value[i] < min)
		{
			value[0] = value[i];
			value[i] = min;
			min = value[0];
		}
		i++;
	}
	int_sort(value + 1, size - 1);
}

int	median(t_stack *stack, int size)
{
	int	*value;
	int	i;

	i = 0;
	value = ft_calloc(size, sizeof(*value));
	if (!value)
		return (inter_mid(stack, size));
	while (i < size)
	{
		value[i] = stack->value;
		stack = stack->next;
		i++;
	}
	int_sort(value, size);
	i = value[size / 2];
	free(value);
	return (i);
}
