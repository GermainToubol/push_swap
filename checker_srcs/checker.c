/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:21 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/25 09:52:10 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int	do_instruction(char *instr, t_stack **stack_a, t_stack **stack_b);

int	read_and_move(t_stack **stack_a, t_stack **stack_b)
{
	char	*instr;

	instr = get_next_line(0);
	while (instr)
	{
		if (!do_instruction(instr, stack_a, stack_b))
		{
			free(instr);
			return (-1);
		}
		free(instr);
		instr = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (args_to_stack(argc, argv, &stack_a)
		|| read_and_move(&stack_a, &stack_b))
	{
		stack_clear(&stack_a);
		stack_clear(&stack_b);
		put_error();
		exit(1);
	}
	if (stack_b == NULL && stack_n_sorted(stack_a, stack_size(stack_a), 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
