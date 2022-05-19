/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 14:20:01 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"

void	stack_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	tmp = *stack;
	while (tmp->next !=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = first;
}
