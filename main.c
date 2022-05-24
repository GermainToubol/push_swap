/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:34:52 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/24 16:45:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"

t_inst	*sort_divide(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_inst	*instruct;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	instruct = NULL;
	if (args_to_stack(argc, argv, &stack_a))
	{
		put_error();
		exit(1);
	}
	divide(&stack_a, &stack_b, stack_size(stack_a), &instruct);
	i = 0;
	while (i++ < 10)
	{
		clean_instructions(&instruct);
		change_instructions(&instruct);
	}
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (instruct);
}

t_inst	*sort_naive(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_inst	*instruct;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	instruct = NULL;
	if (args_to_stack(argc, argv, &stack_a))
	{
		put_error();
		exit(1);
	}
	if (stack_size(stack_a) >= 3)
		insert_naif(&stack_a, &stack_b, stack_size(stack_a), &instruct);
	i = 0;
	while (i++ < 10)
	{
		clean_instructions(&instruct);
		change_instructions(&instruct);
	}
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (instruct);
}


int	main(int argc, char	**argv)
{
	t_inst	*instruct_div;
	t_inst	*instruct_naiv;

	if (argc == 1)
		return (0);
	instruct_div = NULL;
	instruct_naiv = NULL;
	instruct_div = sort_divide(argc, argv);
	if (argc > 3 && argc < 110)
		instruct_naiv = sort_naive(argc, argv);
	if (instruct_naiv == NULL
		|| instruct_len(instruct_div) <= instruct_len(instruct_naiv))
	{
		printf_free_instr(instruct_div);
		free_all_instrs(instruct_naiv);
	}
	else
	{
		printf_free_instr(instruct_naiv);
		free_all_instrs(instruct_div);
	}
	return (0);
}
