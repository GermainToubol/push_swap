/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:47 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 19:11:54 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

static int	do_swap(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instr, "sa\n", 7))
	{
		stack_swap(stack_a, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "sb\n", 7))
	{
		stack_swap(stack_b, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "ss\n", 7))
	{
		stack_swap(stack_a, NULL);
		stack_swap(stack_b, NULL);
		return (1);
	}
	return (0);
}

static int	do_push(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instr, "pa\n", 7))
	{
		stack_push(stack_a, stack_b, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "pb\n", 7))
	{
		stack_push(stack_b, stack_a, NULL);
		return (1);
	}
	return (0);
}

static int	do_rotate(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instr, "ra\n", 7))
	{
		stack_rotate(stack_a, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "rb\n", 7))
	{
		stack_rotate(stack_b, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "rr\n", 7))
	{
		stack_rotate(stack_a, NULL);
		stack_rotate(stack_b, NULL);
		return (1);
	}
	return (0);
}

static int	do_reverse(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instr, "rra\n", 7))
	{
		stack_reverse_rotate(stack_a, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "rrb\n", 7))
	{
		stack_reverse_rotate(stack_b, NULL);
		return (1);
	}
	if (!ft_strncmp(instr, "rrr\n", 7))
	{
		stack_reverse_rotate(stack_a, NULL);
		stack_reverse_rotate(stack_b, NULL);
		return (1);
	}
	return (0);
}

int	do_instruction(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (do_swap(instr, stack_a, stack_b))
		return (1);
	if (do_push(instr, stack_a, stack_b))
		return (1);
	if (do_rotate(instr, stack_a, stack_b))
		return (1);
	if (do_reverse(instr, stack_a, stack_b))
		return (1);
	return (0);
}
