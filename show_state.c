/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:15:33 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 17:25:57 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

void	show_state(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf(" %6s %6s\n", "a", "b");
	ft_printf(" ------ ------\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("% 7d", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			ft_printf("%7s", "");
		if (stack_b)
		{
			ft_printf("% 7d", stack_b->value);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}
