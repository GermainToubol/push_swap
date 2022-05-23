/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:34:52 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/23 11:56:00 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char	*argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_inst	*instruct;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	instruct = NULL;
	if (args_to_stack(argc, argv, &stack_a))
		return (put_error());
	divide(&stack_a, &stack_b, stack_size(stack_a), &instruct);
	clean_instructions(&instruct);
	printf_free_instr(instruct);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
