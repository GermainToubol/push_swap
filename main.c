/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:34:52 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/19 14:56:48 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "push_swap.h"

int	main(int argc, char	*argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (args_to_stack(argc, argv, &stack_a))
		return (put_error());
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
