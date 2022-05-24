/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:06:48 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 11:22:33 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

void	stack_push(t_stack **dest, t_stack **src, t_inst **instruct)
{
	t_stack	*tmp;

	if ((*src) == NULL)
		return ;
	tmp = *src;
	if (tmp->name == '0')
		tmp->name = 'a';
	else
	{
		if (tmp->name == 'a')
		{
			tmp->name = 'b';
			new_instr(instruct, -1);
		}
		else
		{
			tmp->name = 'a';
			new_instr(instruct, 1);
		}
	}
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}
